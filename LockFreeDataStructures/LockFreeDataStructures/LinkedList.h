#pragma once
// include guards
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <utility>
#include <atomic>
#include <assert.h>
#include <limits>
#include <exception>
#include <functional>

template <typename T>
struct basic_node {
    basic_node(T pValue) : value(pValue) {}
    T value{};
    std::atomic<basic_node<T>*> next = nullptr;
};

template <typename T>
class lockless_linked_list {

public:
    lockless_linked_list(const T& value) : m_head(new basic_node<T>(value)), m_counter(1) {}
    void insert(const T& value, size_t index) {
        if (m_counter == 0) { head = new basic_node<T>(value); ++m_counter; return; }
        if (index >= m_counter) throw std::exception("out of range index");
        atomic<basic_node<T>*> p = head;
        if (index) for (size_t idx = 0; p.load(std::memory_order_relaxed) != nullptr && idx < index - 1; p = ReadSafeAddress(p.load(std::memory_order_relaxed)->next));
        insert(p, new basic_node<T>(value));
        ++m_counter;
    }
    void remove(size_t index) {
        if (index >= m_counter) throw std::exception("out of range index");
        atomic<basic_node<T>*> p = m_head;
        if (index) for (size_t idx = 0; p.load(std::memory_order_relaxed) != nullptr && idx < index - 1; p = ReadSafeAddress(p.load(std::memory_order_relaxed)->next));
        removeNode(p);
        --m_counter;
    }
    void print(const std::function<void(const T &value)> &func) {
        for (auto p = m_head.load(std::memory_order_relaxed); p != nullptr; p = ReadSafeAddress(p.load(std::memory_order_relaxed)->next)) {
            func(p.load(std::memory_order_relaxed)->value);
        }
    }
private:
    constexpr const bool IsByteAlligned(const size_t byteBoundary) const {
        return (((uintptr_t)(const void *)(static_cast<basic_node<T>*>(nullptr) + 1)) % (byteBoundary) == 0);
    }
    inline basic_node<T>* ReadSafeAddress(basic_node<T>* ptr) const {
        auto address = reinterpret_cast<uintptr_t>(ptr);
        return reinterpret_cast<basic_node<T>*>((address & 1) ? (address ^ 1) : address);
    }
    inline basic_node<T>* MarkAddress(basic_node<T>* ptr) {
        auto address = reinterpret_cast<uintptr_t>(ptr);
        static_assert(IsByteAlligned(2), "Require the compiler to align addresses at boundaries multiple of 2");
        return reinterpret_cast<basic_node<T>*>(address ^ 1);
    }

    void insert(basic_node<T> *preNode, basic_node<T> *newNode) {
        do {
            auto next = ReadSafeAddress(preNode->next.load(std::memory_order_relaxed));
            newNode->next.store(next);
            if (preNode->next.compare_exchange_weak(next, newNode)) {
                return;
            }
        } while (true);
    }
    void removeNode(basic_node<T> *preNode) {
        do {
            auto nextToDelete = ReadSafeAddress(reinterpret_cast<uintptr_t>(preNode->next));
            auto next = ReadSafeAddress(nextToDelete->next.load(std::memory_order_relaxed));
            if (nextToDelete->next.compare_exchange_weak(next, MarkAddress(next))) {
                    next = ReadSafeAddress(nextToDelete->next);
                    if (preNode->next.compare_exchange(nextToDelete, next)) {
                        return;
                    }
                    else {
                        nextToDelete->next = ReadSafeAddress(nextToDelete->next);
                    }
            }
        } while (true);
    }
    std::atomic<basic_node<T>*> m_head;
    std::atomic<size_t> m_counter;
};
#endif
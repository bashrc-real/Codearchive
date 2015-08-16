#pragma once
// include guard
#ifndef __ALLOCATION_TRACKER__
#define __ALLOCATION_TRACKER__


#ifdef TRACK_MEMORY

#include <mutex>
#include <memory>
#include <map>
#include <iostream>
#include <assert.h>

// static members that need to be defined in implementation
//  std::map<void*, const char*> m_objectCollection;
//  std::mutex m_collectionLock;
class AllocMapper{
    public:
        static AllocMapper* GetAllocMapper(){
            std::lock_guard<std::mutex> lock(m_lock);
            if (!m_allocObject){
                m_allocObject.reset(new AllocMapper());
            }
            return m_allocObject.get();
        }
        
        void AddObjectCreated(void *ptr, const char* objectName){
            std::lock_guard<std::mutex> lock(m_collectionLock);
            auto ret = m_objectCollection.emplace(ptr, objectName);
            assert(ret.second);
        }
        
        void RemoveObjectDeleted(void *ptr){
            std::lock_guard<std::mutex> lock(m_collectionLock);
            auto deleted = m_objectCollection.erase(ptr);
            assert(deleted);
        }
        
        ~AllocMapper(){
            if (!m_objectCollection.empty()){
                std::cout<<"Number of outstanding allocations:"<<m_objectCollection.size()<<std::endl;
                for (const auto &iter : m_objectCollection){
                    std::cout<<iter.first<<" "<<iter.second<<std::endl;
                }
                #ifdef _MSC_VER
                    DebugBreak();
                #else
                    assert(false);
                #endif
            }
        }
    private:
        AllocMapper() {}
        AllocMapper(AllocMapper const&) = delete;
        void operator=(AllocMapper const&) = delete;
        std::map<void*, const char*> m_objectCollection;
        std::mutex m_collectionLock;

        static std::unique_ptr<AllocMapper> m_allocObject;
        static std::mutex m_lock;
};

class AllocTracker {
    public: 
        AllocTracker(const char *objectName, void *parentAddr){
            m_parentPointer = parentAddr;
            AllocMapper::GetAllocMapper()->AddObjectCreated(parentAddr, objectName);
        }
        ~AllocTracker(){
            AllocMapper::GetAllocMapper()->RemoveObjectDeleted(m_parentPointer);
        }
    private:
        void *m_parentPointer;
};
#define DECLARE_ALLOC() AllocTracker m_allocTrackerObj{__PRETTY_FUNCTION__, reinterpret_cast<void*>(this)}
#define DECLARE_ALLOC_NAME(x) AllocTracker m_allocTrackerObj{x, reinterpret_cast<void*>(this)}

#else
#define DECLARE_ALLOC()
#define DECLARE_ALLOC_NAME(x)
#endif

#endif // include guard
#include <vector>
#include <map>
#include <deque>
using namespace std;

struct Node{
    int value;
    Node *next;
};

// 1->2->3,  2->3

int getValue(Node *node){
    if (node == nullptr) return 0;
    return node->value;
}

Node* getNext(Node *node){
    if (node == nullptr) return nullptr;
    return node->next;
}

Node* Add(Node* number1, Node* number2){
    if (number1 == nullptr) return number2;
    if (number2 == nullptr) return number1;

    int carry = 0;
    Node* head = nullptr;
    Node* prev = nullptr;
    for(auto iter1 = number1, iter2 = number2; iter1 != nullptr || iter2 != nullptr; iter1 = getNext(iter1), iter2 = getNext(iter2)){
        int value = getValue(iter1) + getValue(iter2) + carry;
        if (value > 10){
            value -= 10;
            carry = 1;
        }
        auto newNode = new Node{value};
        if (head == nullptr){
            head = prev = newNode;
            prev = newNode;
            }else{
            prev->next = newNode;
        }
    }

    if (carry > 1){
        prev->next = new Node{carry, nullptr};
    }

    return head;
}

int main(){
}

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <thread>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node* random;
};


void fillRandomPointer(Node *root, int size){
    for(auto node = root; node != nullptr; node = node->next){
        int candidateIndex = rand()%1000;
        auto candidateNode = root;
        int cntr = 0;
        for (cntr = 0; cntr < candidateIndex; ++cntr, candidateNode = candidateNode->next);
        node->random = candidateNode;
    }
}

void CreateAndFillLinkedList(Node* &root, int size = 100000){
    Node* &localRoot = root;
    localRoot =  new Node{1, nullptr, nullptr};
    auto node = localRoot; 
    for(int cntr = 1; cntr < size; ++cntr, node = node->next){
        auto tmpNode = new Node{cntr + 1, nullptr, nullptr};
        node->next = tmpNode;
    }
    fillRandomPointer(localRoot, size); 
}



int main(){
    Node *root;
    CreateAndFillLinkedList(root);
    // for(auto localNode = root; localNode != nullptr; localNode = localNode->next){
    //     cout << localNode->value<< " " << localNode->random->value << endl;
    // }
}

#include <array>
#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
const int numberOfItems = 1000000; 
long long sm = 0;
long long val = 0;
array<volatile int, 10> Data{10,1,2,2,4,4,5,1,23,22};
volatile int indx = 0;

void func1(vector<int> &container){
    container.reserve(numberOfItems);
    for (int i = 0; i < numberOfItems; i++){
        int data = Data[indx];
        container.push_back(data);
        indx = (indx+1)%10;
    }
    return;
}
int main(){
    auto fun1 = [](){
        auto start = chrono::system_clock::now();
        vector<int> value;
        func1(value);
        for(auto &v : value){
            sm+=v;
        }
        auto end = chrono::system_clock::now();
        val += (end - start).count();
    };
    array<thread, 10> threads;
    for(auto &v : threads){
        v = thread(fun1);
    }
    this_thread::sleep_for(chrono::seconds(2));
    for (auto &v : threads){
        v.join();
    }
    cout<<sm<<endl;
    cout<<val<<endl;
}


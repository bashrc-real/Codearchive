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
class obj{
public:
    const vector<int>& func1(){
        m_container.reserve(numberOfItems);
        for (int i = 0; i < numberOfItems; i++){
            int data = Data[indx];
            m_container.push_back(data);
            indx = (indx+1)%10;
        }
        return m_container;
    }
private:
    vector<int> m_container;
};    
int main(){
    auto fun1 = [](){
        auto start = chrono::system_clock::now();
        obj ob; 
        const vector<int>& value = ob.func1();
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


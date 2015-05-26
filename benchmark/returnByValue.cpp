#include <limits>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;
const unsigned int max_buffer = 1024;
char buffer[max_buffer];
void setArrayBuffer(){
    for(unsigned i = 0; i < max_buffer; i++){
        buffer[i] = rand() % 26 +'a';
    }
}
int getBufferItem(int seedIdx){
    static const unsigned int MOD = 1e9+7;
    unsigned int dx = ((numeric_limits<unsigned int>::max() + seedIdx*MOD) % MOD + MOD) % max_buffer;
    return buffer[dx]; 
}
vector<unsigned char> readString(){
    vector<unsigned char> x;
    unsigned int iters = 100;
    x.reserve(iters);
    while(iters--){
        x.push_back(getBufferItem(iters));
    }
    return x;
}
void readString(vector<unsigned char> &x){
    unsigned int iters = 100;
    x.reserve(iters);
    while(iters--){
        x.push_back(getBufferItem(iters));
    }
}
int main(){
    auto start = std::chrono::high_resolution_clock::now();
    unsigned int cntr = 0;
    setArrayBuffer();
    for(int i = 0; i < 100000; i++){
#ifdef PASS_BY_VALUE
        vector<unsigned char> x = readString();
#else
        vector<unsigned char> x;
        readString(x);
#endif
        for (auto &iter:x){
            cntr += iter;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    cout<<std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<endl;
    cout<<cntr<<endl;
}
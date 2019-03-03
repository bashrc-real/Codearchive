#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool solve(const vector<string> &values, int partitions){
    auto len = to_string(partitions).size();
    int cntr = 0;
    int idx = 0;
    int len = 0;
    int offset = 0;
    while(idx < values.size()){
        len += values[idx].size();
        if (len + offset > 30){
            len = values[idx].size();
            ++cntr;
            if (cntr > )
        }

    }
}
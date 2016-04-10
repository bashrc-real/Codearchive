// gcj2.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

int solve(string inp) {
    char prev = inp[0];
    int cntr = (prev == '-');
    for (size_t idx = 1, sz = inp.size(); idx < sz; ++idx) {
        if (inp[idx] != prev) {
            if (prev == '+') cntr += 2;
            prev = inp[idx];
        }
    }
    return cntr;
}
int main(){
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string inp;
        cin >> inp;
        cout << "Case #" << i << ": " << solve(inp)<< endl;
    }
    return 0;
}


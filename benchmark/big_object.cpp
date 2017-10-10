#include <limits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
int test = 1;
struct val{
 string tmp[100];
};

void solve(){
    vector<val> dumb;
    dumb.reserve(100000);
    for(int i=0; i<100000; i++){
        val x;
        dumb.push_back(x);
        for(int j=0; j<100; j++){
            dumb.back().tmp[j] = "helios";
        }
        for(int j=1;j<100;j++){
            dumb.back().tmp[j]=dumb.back().tmp[j-1];
        }
    }
    
    
}
int main(){
    #ifndef ONLINE_JUDGE
    test = 3;
    #endif
    for (int i=0;i<test;i++){
        solve();
    }
}


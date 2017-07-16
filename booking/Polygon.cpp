// Given a list of arrays with 4 integers tell how many of those arrays represent
// square, rectangle, arbitrary polygon, none
 
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Check(const vector<int> &sides){
    auto mxSide = *max_element(sides.begin(), sides.end());
    auto mnSide = *min_element(sides.begin(), sides.end());
    if(mnSide <= 0) return 2;
    if (mxSide == mnSide) return 0;
    auto sm = accumulate(sides.begin(), sides.end(), 0);
    if (mxSide >= sm - mxSide) return 2;
    if (sides[0] == sides[2] && sides[1] == sides[3]) return 1;
    return 2;
}
int main() {
    int a,b,c,d;
    int cntr[3] = {0};
    string str;
    while(getline(cin, str)){
        stringstream buffer(str);
        if (!(buffer >> a >> b >> c >> d)){
            break;
        }  
        vector<int> sides{a,b,c,d};
        ++cntr[Check(sides)];
    }
    cout << cntr[0] <<" "<<cntr[1] << " "<<cntr[2] << endl;
    return 0;
}
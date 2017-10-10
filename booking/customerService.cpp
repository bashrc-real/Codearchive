// There are M customer care executives in your company. Each exec can handle one call at a time
// You are given a log of format [S, E] where S = Start time of call and E= End time of call.
// You have to tell minimum number of execs needed
// For eg for input {[1, 100][2,50], [10,20]} the answer would be 3
// for input {[1,10][11,20][15,18]} the answer would be 2. Any one would handle the first call and then free at 10.
// Then he can take the next call at 11. When the call comes at 15 the second one would handle it.

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
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M;
    cin >> M;
    int N;
    cin >> N;
    vector<pair<int,bool>> values;
    for(int i = 0; i < N; ++i){
        int tm1, tm2;
        cin >> tm1 >> tm2;
        values.push_back(make_pair(tm1, false));
        values.push_back(make_pair(tm2, true));
    }
    sort(values.begin(), values.end());
    int cntr = 0;
    int mxCntr = 0;
    for(auto x : values){
        if (x.second) cntr -= 1;
        else cntr += 1;
        mxCntr = max(mxCntr, cntr);
    }
    cout << max(mxCntr - M, 0) << endl;
    return 0;
}
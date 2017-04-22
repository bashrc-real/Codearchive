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
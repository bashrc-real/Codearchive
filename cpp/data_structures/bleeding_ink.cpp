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
void Solve(){
    int H,W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<vector<int>> V(H, vector<int>(W, 0));
    vector<pair<int, pair<int, int>>> vs;
    for(int i = 0; i < N; ++i){
        int r,c,v;
        cin >> r >> c >> v;
        V[r][c] = max(V[r][c], v);
        vs.push_back(make_pair(v, make_pair(r, c)));
    }
    
    sort(vs.begin(), vs.end());
     for(int i = vs.size() - 1; i >= 0; --i){
        stack<pair<pair<int, int>,int>> dfs;
        auto start = vs[i].second;
        auto r = start.first;
        auto c = start.second;
        if (vs[i].first < V[r][c]) continue;
        dfs.push(make_pair(make_pair(r ,c), vs[i].first));
        while(!dfs.empty()){
            auto nxt = dfs.top();dfs.pop();
            auto x = nxt.first.first;
            auto y = nxt.first.second;
            auto value = nxt.second;
            for(int dx = -1; dx <= 1; ++dx){
                for(int dy = -1; dy <= 1; ++dy){
                    if ((dx == 0 && dy == 0)) continue;
                    auto nxtX = x + dx;
                    auto nxtY = y + dy;
                    auto nxtV = value - abs(dx) - abs(dy);
                    if (nxtX < V.size() && nxtX >= 0 && nxtY >= 0 && nxtY < V[nxtX].size() && V[nxtX][nxtY] < nxtV){
                        V[nxtX][nxtY] = nxtV;
                        dfs.push(make_pair(make_pair(nxtX, nxtY), nxtV));
                    }
                }
            }
        }
    }
    
    long long sm = 0;
    for(int i = 0; i < H; ++i){
        
        for(int j = 0; j < W; ++j) { cerr << V[i][j] << " "; sm += (long long)V[i][j]; }
        cerr << endl;
    }
    
    cout << sm << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--) Solve();
    return 0;
}
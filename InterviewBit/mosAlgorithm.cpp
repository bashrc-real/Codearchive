// square root decomposition using MOS algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C[1000001]={};
int query(const vector<int> &elems, int L, int R, int &currentL, int &currentR, int &answer){
    while (currentL < L){
        --C[elems[currentL]];
        if (C[elems[currentL]] == 0) --answer;
        ++currentL;
    }
    while(currentL > L){
        ++C[elems[currentL-1]];
        if (C[elems[currentL-1]] == 1) ++answer;
        --currentL; 
    }
    while(currentR <= R){
        ++C[elems[currentR]];
        if (C[elems[currentR]] == 1) ++answer;
        ++currentR;
    }
    while (currentR > R + 1){
        --C[elems[currentR-1]];
        if (C[elems[currentR-1]] == 0) --answer;
        --currentR;
    }
    return answer;
}

vector<int> solve(const vector<int> &elems, vector<pair<pair<int,int>, int>> &queries){
    const int block = elems.size();
    sort(queries.begin(), queries.end(), [block](const pair<pair<int,int>, int> &l,const pair<pair<int,int>, int> &r){
        return l.first.first/block == r.first.first/block ? l.first.second < r.first.second : l.first.first/block < r.first.first/block;
    });
    int answer = 0;
    int currentL = 0, currentR = 0;
    vector<int> result(queries.size());
    for (auto q : queries){
        auto res = query(elems, q.first.first, q.first.second, currentL, currentR, answer);
        result[q.second] = res;
    }
    return result;
}

void solve(){
    int N;
    cin >> N;
    vector<int> elems(N);
    for (int i = 0; i < N; ++i) cin >> elems[i];
    int q;
    cin >> q;
    vector<pair<pair<int, int>, int>> queries;
    queries.reserve(q+1);
    int cntr = 0;
    while(q--){
        int f1,f2;
        cin >> f1 >> f2;
        --f1;--f2;
        queries.push_back(make_pair(make_pair(f1, f2), cntr));
        ++cntr;
    }
    auto res = solve(elems, queries);
    for (auto ans : res) cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    solve();
}
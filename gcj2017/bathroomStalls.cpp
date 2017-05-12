#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


auto GetLeft(const set<int> &visited, int N){
    auto it = visited.lower_bound(N);
    return *(--it);
}
auto GetRight(const set<int> &visited, int N){
    return *visited.upper_bound(N);
}

void solve(){
    int N, k;
    cin >> N >> k;
    set<int> visited;
    visited.insert(0); visited.insert(N+1);
    for (int i = 0; i < k; ++i){
        int l=0,r=0;
        int picked = 0;
        for (int j = 1; j <= N; ++j){
            if (visited.find(j) == visited.end()){
                auto L = j - GetLeft(visited, j) - 1;
                auto R = GetRight(visited, j) - j - 1;
                auto diff = min(R, L);
                if (diff > min(l,r)){
                    picked = j;
                    l = L;
                    r = R;    
                }else if (diff == min(l,r)){
                    if (max(r, l) < max(R, L)){
                         picked = j;
                         l = L;
                         r = R;   
                    }   
                }   
            }
        }
        visited.insert(picked);
        if (i==k-1){
            cout << max(l, r) << " " << min(l, r)<< "\n";
        }
    }
}

int main(){
    int t; 
    cin >> t;
    for (int i = 1; i <=t ; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
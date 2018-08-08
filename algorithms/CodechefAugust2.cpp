#include <vector>
#include <algorithm>
#include <iostream>
#include<set>
#include <cstdio>
#include <array>

using namespace std;

auto pre(){
    const int mxBits = 31;
    array<long long, (32 * 31) / 2> values;
    int idx = 0;
    for(unsigned cntr = 0; cntr <= mxBits; ++cntr){
        for(unsigned c2 = cntr + 1; c2 <= mxBits; ++c2){
            values[idx++] = (1ll << cntr) | (1ll << c2);
        }
    }
    
    sort(values.begin(), values.end());
    return values;
}

template <typename container>
void solve(const container &values){
    int N;
    cin >> N;
    auto idx = distance(values.begin(), lower_bound(values.begin(), values.end(),  N));
    long long ans = 2e9 + 1;
    for(int cntr = -1; cntr <= 0; ++cntr){
        auto i = idx + cntr;
        if (i >= values.size() || i < 0) continue;
        ans = min(ans, abs(values[i] - N));
    }

    cout << ans << "\n";
}

int main(){
    int t;
    std::ios::sync_with_stdio(false);

    cin >> t;
    auto v = pre();
    while(t--){
        solve(v);
    }
}
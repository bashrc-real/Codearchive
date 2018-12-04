#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void Solve(){
    long long n,k;
    cin >> n >> k;
    const long long mod = 1e9+7;
    long long product = 1;
    int value = 0;
    long long baseValue = n/k;

    if (((k * (k+1))/2 > n)){
        cout << -1 << "\n";
        return;
    }
    
    vector<int> values;
    values.reserve(k);
    int rem = n % k; 
    for (long long i = baseValue - 1, cntr = 0; cntr < k/2; ++cntr, --i){
        values.push_back(i);
    }

    if (k&1) {
        values.push_back(baseValue);
    } else if (rem != 0){
        int idx = 0;
        while(rem && idx < values.size()) {++values[idx];--rem;++idx;}
    }

    for (long long i = baseValue + 1, cntr = 0; cntr <  k/2; ++cntr, ++i){
        values.push_back(i);
    }

    sort(values.begin(), values.end());
    int cntr = 0;
    
    for(int i = values.size() - 1;  rem > 0; --i){
        cerr << values[i] << "!!!##<<<" << endl;
        ++cntr;
        if (cntr >= 2 *k) break;
        if (i < 0) i = values.size() - 1;
        if (i == values.size() - 1 || values[i] + 1 != values[i+1]) { --rem; ++values[i];}
    }

    for(int i = values.size() - 1; i >= 0; --i){
        cerr << values[i] << "##<<<" << endl;
        product = (((product * values[i]) % mod) * (values[i]-1)) % mod;
    }
    cout << product << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        Solve();
    }
}
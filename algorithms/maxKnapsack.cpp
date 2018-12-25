#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

#define ASS(X, Y) { ASSF(X, Y);}

template<typename T>
void ASSF(T a, T b){
    if (a <= b){
        cout << a << " " << b;
    }

    assert(a > b);
}

long long solve(int N, int M, const vector<int> &W, const vector<int> &V, vector<long long> &fib){
    long long ans = 0;
    reverse(fib.begin(), fib.end());
    unordered_set<long long> seen;
    for(auto v : fib){
        long long localAns = 0;
        long long weight = 0;
        for(int idx = 1; idx <= ((1<<(N)) - 1); ++idx){
            if (seen.find(idx) != seen.end()) continue;
            int bit = 0;
            int tmp = idx;
            localAns = 0;
            weight = 0;
            while(tmp){
            
                if (tmp & 1){
                    ASS(V[bit] * v, 0ll);
                    if (W[bit] * v  == 0) cerr <<"###" << bit << endl;
                    ASS(W[bit] * v, 0ll);
                    ASS(bit, -1);
                    ASS(N, bit);
                    auto p = localAns;
                    localAns += (V[bit] * v);
                    ASS(localAns, p);
                    p = weight;
                    weight += (W[bit] * v);
                    ASS(weight, p);
                    //cout << idx << " " << v << " " << weight << " " << localAns << endl;

                    if (weight > M) break;
                
                }
                tmp >>= 1;
                ++bit;
            }

            if (weight > M) continue;
            seen.insert(idx);
           ans = max(ans, localAns);
        }
    }

    return ans;
}

long long calculate(long  N, long M, const vector<int> &W, const vector<int> &V){
    vector<long long> fib;
    fib.push_back(1);
    fib.push_back(2);
    while(true){
        int v = fib.back() + fib[fib.size() - 2];
        if (v < 100) fib.push_back(v);
        else break;
    }
    //for(auto x : fib) cout << x << "#";
    cout << endl;
    return solve((int)N, (int)M, W, V, fib); 
}

int main(){
    int N, M,t;
    cin >> t;
    while(t--){
        cin >> N >> M;
        vector<int> W(N);
        vector<int> V(N);
        for(int i = 0; i < N; ++i) cin >> W[i];
        for(int i = 0; i < N; ++i) cin >> V[i];
        cout << calculate(N, M, W, V) << endl;
    }

    for(int i = 0; i < 10000; ++i){
        vector<int> values(20);
        for(int i = 0; i < 20; ++i)
        values[i] = ((rand() % (1000000000)) + 1);
        cout << calculate(20, rand() + 1, values, vector<int>(20, rand()%700 + 1));
    }
}


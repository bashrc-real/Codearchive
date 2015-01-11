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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define PR(x) cout<<#x<<"="<<x<<endl
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RP(i,a) for(int i=0;i<a;i++)
#define tr(iter,container) for(auto iter = container.begin();iter!=container.end();iter++) 
#define S(x) cin>>x
#define PRARR(x,n) for(int i=0;i<n;i++) cout<<#x<<"["<<i<<"]= "<<x[i]
#define rd(arr,i,n) for(int i=0;i<n;i++) cin>>arr[i]
#define PB push_back
#define SUM(arr,n,sum) {sum=0;for(int i=0;i<n;i++) sum+=arr[i]; }
#define VC vector
#define CLR(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
int test = 1;
template <typename T, size_t const maxVal>
class BIT{
    public:
        BIT(){
            m_tree.resize(maxVal);
        
        }
        void update(int idx, T val){
            while(idx<=maxVal){
                m_tree[idx] += val;
                idx += (idx & -idx);
            }    
        }
        T Read(int idx){
           long long sm = 0;
           while(idx>0)s{
            sm += m_tree[idx];
            idx -= (idx & -idx);
           }
           return T(sm); 
        }
    private:
        vector<T> m_tree;
};
void solve(){
    int N;
    S(N);
    BIT bt(N+1);
    REP(i,0,N){
        int tmp;
        S(tmp);
        bt.update(i, tmp);
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


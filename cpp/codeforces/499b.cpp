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
#include <array>
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

void solve(){
    vector<int> values;
    int n,m;
    cin >> n >> m;
    vector<int> cntr(101, 0);
    for(int i = 0; i < m; ++i){
        int t;
        cin >> t;
        ++cntr[t];
    }

   for(int i = 1; i <= 105; ++i){
       int ans = 0;
       for(int j = 0; j <= 100; ++j) ans += cntr[j]/i;
       if (ans < n){
           cout << i - 1 << endl;
           return;
       }
   }
    
    cout << -1 << endl;
    // m = 101;
    // set<pair<int,pair<int,int>>> v;
    // for(int i = 0; i < m;++i) v.emplace(-cntr[i], make_pair(0,i));
    // vector<int> assigned(m, 0);
    // int C = 0;
    // while(!v.empty()){
    //     auto nxt = v.begin();
    //     auto tmp = nxt;
    //     auto nxtV = *nxt;
    //     auto nxtS = ++tmp;
    //     auto nxtSV = 0;
    //     int reqd = n - C;
    //     if (reqd == 0) break;
    //     if (nxtS != v.end()){
    //      //   cerr << nxtV.first << ","<<nxtV.second.second << "==" << (*nxtS).first << ","<< (*nxtS).second.second << endl;
    //         auto diff = max(1, (-nxtV.first - (-(*nxtS).first)));
    //         assigned[nxtV.second.second] += min(reqd, diff);
    //         C = min(C + diff, n);
    //         v.emplace(nxtV.first + diff, make_pair(assigned[nxtV.second.second],nxtV.second.second));
    //     }else{
    //          assigned[nxtV.second.second] += min(reqd, -nxtV.first);
    //          C = min(C - nxtV.first, n);
    //     }
    //     v.erase(nxt);
    // } 
    
    // int ans = (1<<29);
    // for(int i = 0; i < m; ++i) { if(assigned[i] > 0) ans = min(ans, cntr[i]/assigned[i]); }
    // cout << (ans == (1<<29) ? 0 : ans) << endl;
}


int main(){
    int test = 1;
    #ifndef ONLINE_JUDGE
    test = 5;
    #endif
    for(int i = 0; i < test; ++i) solve();
}
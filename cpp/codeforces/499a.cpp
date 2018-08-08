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
    int n,k;
    cin >> n >> k;
    string inp;
    cin >> inp;
    vector<int> values(26, 0);
    for(auto x : inp) ++values[x - 'a'];
    int cntr = 0;
    int ans = 0;
    int runner = 0;
    while((cntr < k) && n && runner < 26){
        if(values[runner] > 0){
            ans += (runner + 1);
            --values[runner];
            runner = (runner + 1);
            ++cntr;
            --n;
        }

        runner = (runner + 1);
    
    }
    
    cout << (cntr == k ? ans : -1) << endl;
}


int main(){
    int test = 1;
    #ifndef ONLINE_JUDGE
    test = 5;
    #endif
    for(int i = 0; i < test; ++i) solve();
}
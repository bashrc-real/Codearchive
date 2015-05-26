#include <limits>
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
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define PR(x) cout<<#x<<"="<<x<<endl
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a,b) for(decltype(b) i=a;i<b;i++)
#define RP(i,a) for(decltype(a) i=0;i<a;i++)
#define tr(iter,container) for(auto iter = container.begin();iter!=container.end();iter++) 
#define S(x) cin>>x
#define PRARR(x,n) for(decltype(n) i=0;i<n;i++) cout<<#x<<"["<<i<<"]= "<<x[i]
#define rd(arr,i,n) for(decltype(n) i=0;i<n;i++) cin>>arr[i]
#define PB push_back
#define SUM(arr,n,sum) {sum=0;for(decltype(n) i=0;i<n;i++) sum+=arr[i]; }
#define VC vector
#define CLR(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
int test = 1;
struct val{
 string tmp[100];
};

void solve(){
    vector<val> dumb;
    dumb.reserve(100000);
    for(int i=0; i<100000; i++){
        val x;
        dumb.push_back(x);
        for(int j=0; j<100; j++){
            dumb.back().tmp[j] = "helios";
        }
        for(int j=1;j<100;j++){
            dumb.back().tmp[j]=dumb.back().tmp[j-1];
        }
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


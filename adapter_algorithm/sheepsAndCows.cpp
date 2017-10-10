#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<utility>
#define PR(x) printf(#x"=%d\n",x)
#define PRL(x) printf(#x"=%lld\n",x)
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a) for(int i=0;i<a;i++)
#define READ(x) scanf("%d",&x)
#define PRARR(x,n) for(int i=0;i<n;i++)printf(#x"[%d]=\t%d\n",i,x[i])
#define MOD 1000000007
using namespace std;
 
inline long long po(long long  a, int b)
{
        long long x=1,y=a; 
        while(b > 0)
        {
                if(b%2 == 1)
                {
                        x=(x*y);
                        if(x>MOD) x%=MOD;
                }
                y = (y*y);
                if(y>MOD) y%=MOD; 
                b /= 2;
        }
        return x;
}
inline long long InverseEuler(long long n)
{
        return po(n,MOD-2);
}
 
vector<long long> fctMOD;
vector<long long> fctMOD2; 
inline long long comb(int n, int r)
{
//PR(n);PR(r);
if(n==r||r==0) return 1;
      else if(r==1) return n;
          else
          { 
          long long toRet= ((fctMOD[n]*fctMOD2[n-r])%MOD*fctMOD2[r])%MOD;
          
          return toRet;
          }
} 

/*
 * Complete the function below.
 */

int findConnectedComponents(const vector<string> &grid){
   stack<pair<int, int>> dfs;
   bool visited[5001][5001];
   for (int i = 0; i < grid.size(); ++i){
       for (int j = 0; j < grid[i].size(); ++j) visited[i][j] = false;
   }
   int cntr = 0;
   for (int i = 0; i < grid.size(); ++i){
       for (int j = 0; j < grid[i].size(); ++j){
           if (visited[i][j]) continue;
           if (grid[i][j] == 'N')  continue;
           dfs.push(make_pair(i, j));
           while(!dfs.empty()){
                auto nxt = dfs.top();dfs.pop();
                if (visited[nxt.first][nxt.second]) continue;
                visited[nxt.first][nxt.second]=true;
                if (nxt.first + 1 < grid.size()){
                   if (grid[nxt.first+1][nxt.second] == 'Y') dfs.push(make_pair(nxt.first +1 , nxt.second));
                }
                if (nxt.second + 1 < grid[0].size()){
                   if (grid[nxt.first][nxt.second + 1] == 'Y') dfs.push(make_pair(nxt.first, nxt.second + 1));
                }
                if (nxt.first > 0){
                    if (grid[nxt.first-1][nxt.second] == 'Y') dfs.push(make_pair(nxt.first - 1, nxt.second));
                }
                if(nxt.second > 0){
                    if (grid[nxt.first][nxt.second - 1] == 'Y') dfs.push(make_pair(nxt.first, nxt.second - 1));
                }
                      
           }
           ++cntr;
       }
   }
   return cntr;
}
int Group(vector <string> grid) {
    int r,c;
    r = grid.size();
    c = grid[0].size();
    auto N = findConnectedComponents(grid);
    long long answer = 0;
    // fctMOD.clear();fctMOD2.clear();
    // fctMOD.resize(N + 1); fctMOD2.resize(N+1);
    // fctMOD[0]=1;fctMOD[1]=1;
    // fctMOD2[0]=1;fctMOD2[1]=1;
    // for(int i=2;i<=N;i++){
    //     fctMOD[i]=(i*fctMOD[i-1])%MOD;
    //     fctMOD2[i]=InverseEuler(fctMOD[i])%MOD;
    // }

    return po(2, N-1) % MOD;
}

int main(){
    cout << Group(vector<string>{"YNNY", "NYNY", "NYNN"}) << endl;
    cout << Group(vector<string>{"NNNNN"}) << endl;
}





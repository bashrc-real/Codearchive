//  When Sergeant Argus's army assembles for drilling, they stand in the shape of an N by N square grid, with exactly one soldier in each cell. Each soldier has a certain height.
// 
// Argus believes that it is important to keep an eye on all of his soldiers at all times. Since he likes to look at the grid from the upper left, he requires that:
// 
//     Within every row of the grid, the soldiers' heights must be in strictly increasing order, from left to right.
//     Within every column of the grid, the soldiers' heights must be in strictly increasing order, from top to bottom. 
// 
// Although no two soldiers in the same row or column may have the same height, it is possible for multiple soldiers in the grid to have the same height.
// 
// Since soldiers sometimes train separately with their row or their column, Argus has asked you to make a report consisting of 2*N lists of the soldiers' heights: one representing each row (in left-to-right order) and column (in top-to-bottom order). As you surveyed the soldiers, you only had small pieces of paper to write on, so you wrote each list on a separate piece of paper. However, on your way back to your office, you were startled by a loud bugle blast and you dropped all of the pieces of paper, and the wind blew one away before you could recover it! The other pieces of paper are now in no particular order, and you can't even remember which lists represent rows and which represent columns, since you didn't write that down.
// 
// You know that Argus will make you do hundreds of push-ups if you give him an incomplete report. Can you figure out what the missing list is? 
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

auto solve(vector<vector<int>> values){
	map<int, int> cnt;
	for(int i=0, sz = values.size();i<sz;++i)
	{
		for(int j=0;j<values[i].size();j++)
		{
			++cnt[values[i][j]]; 
		}
	}
	vector<int> result;
	for(auto var : cnt)
	{
		if (var.second & 1) result.push_back(var.first);
	}
	return result;
}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		cout << "Case #"<<i<<": ";
		int N; 
		cin >> N;
		vector<vector<int>> cntr(2*N - 1, vector<int>(N));
		for (int k = 0 ; k < 2*N -1; ++k){
			for (int j = 0; j < N; ++j){
				cin >> cntr[k][j];
			}
		}
		auto res = solve(cntr);
		for (auto v : res){
			cout << v <<" ";
		}
		cout << endl;
	}
}

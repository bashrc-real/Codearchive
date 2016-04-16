//  On the game show The Last Word, the host begins a round by showing the contestant a string S of uppercase English letters. The contestant has a whiteboard which is initially blank. The host will then present the contestant with the letters of S, one by one, in the order in which they appear in S. When the host presents the first letter, the contestant writes it on the whiteboard; this counts as the first word in the game (even though it is only one letter long). After that, each time the host presents a letter, the contestant must write it at the beginning or the end of the word on the whiteboard before the host moves on to the next letter (or to the end of the game, if there are no more letters).
// 
// For example, for S = CAB, after writing the word C on the whiteboard, the contestant could make one of the following four sets of choices:
// 
//     put the A before C to form AC, then put the B before AC to form BAC
//     put the A before C to form AC, then put the B after AC to form ACB
//     put the A after C to form CA, then put the B before CA to form BCA
//     put the A after C to form CA, then put the B after CA to form CAB
// 
// The word is called the last word when the contestant finishes writing all of the letters from S, under the given rules. The contestant wins the game if their last word is the last of an alphabetically sorted list of all of the possible last words that could have been produced. For the example above, the winning last word is CAB (which happens to be the same as the original word). For a game with S = JAM, the winning last word is MJA.
// 
// You are the next contestant on this show, and the host has just showed you the string S. What's the winning last word that you should produce? 

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

vector<string> lst;
auto dfs(const string &s, string curString, int idx){
	if (idx == s.size()) {
		lst.push_back(curString);
		return;
	}
	auto nxtMove = max(curString + s[idx], s[idx]+curString);
	dfs(s,move(nxtMove), idx+1);
}
auto solve(string s){
	dfs(s, "",0);
	sort(lst.begin(), lst.end());
	return lst.back();
}	

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		lst.clear();
		string s;
		cin >> s;
		cout << "Case #"<<i<<": "<<solve(s) << endl;
	}
}

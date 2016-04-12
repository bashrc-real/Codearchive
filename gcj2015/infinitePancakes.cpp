#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;

int Solve(const vector<int> &S){
	int mn = numeric_limits<int>::max();
	for (int h = 1; h <= 1000; ++h){
		int cntr = h;
		for (auto v : S){
			cntr += ((v/h) - (v%h==0));
		}
		mn = min(mn, cntr);
	}
	return mn;
}

int main(){
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 1; i <= t; ++i){
		int N;
		cin >> N;
		vector<int> V(N);
		for (int j = 0 ; j < N; ++j) cin >> V[j];
		cout << "Case #" << i << ": "<<Solve(V)<<endl;
	}
}
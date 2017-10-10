// At the Infinite House of Pancakes, there are only finitely many pancakes, but there are infinitely many diners who would be willing to eat them! When the restaurant opens for breakfast, among the infinitely many diners, exactly D have non-empty plates; the ith of these has Pi pancakes on his or her plate. Everyone else has an empty plate.
// 
// Normally, every minute, every diner with a non-empty plate will eat one pancake from his or her plate. However, some minutes may be special. In a special minute, the head server asks for the diners' attention, chooses a diner with a non-empty plate, and carefully lifts some number of pancakes off of that diner's plate and moves those pancakes onto one other diner's (empty or non-empty) plate. No diners eat during a special minute, because it would be rude.
// 
// You are the head server on duty this morning, and it is your job to decide which minutes, if any, will be special, and which pancakes will move where. That is, every minute, you can decide to either do nothing and let the diners eat, or declare a special minute and interrupt the diners to make a single movement of one or more pancakes, as described above.
// 
// Breakfast ends when there are no more pancakes left to eat. How quickly can you make that happen? 

// Solution: Lets say we didn't allow the number of pancakes on any plate to increase beyond h. Note that the 
// time period when we actually prevent the pancakes from growing beyond h doesn't matters.  
// Try out all possible values of h and pick the minimum one.

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
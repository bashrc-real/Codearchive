// given a number N find out the minimum number of perfect squares that sum to number

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SumOfSquares(int N){
    vector<int> dp(N+1, N + 1);
    dp[0] = 0;
    for(int i = 0; i <= N; ++i){
        for(int j = 1; j <= i/j; ++j){
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    return dp[N];
}

int main(){
    int N;
    while (cin >> N){
        auto value = SumOfSquares(N);
        cout << value << endl;
    }
}
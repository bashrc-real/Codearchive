// given a number N find out the minimum number of perfect squares that sum to number

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> preCompute(int N){
    auto sqrtN = sqrt(N);
    vector<int> values;
    values.reserve(sqrtN);
    for(int i = 1; i <= sqrtN; ++i) values.push_back(i*i);
    return values;
}

int SumOfSquares(int N){
    auto squares = preCompute(N);
    vector<int> dp(N+1, 10000000);
    for(int i = 0; i <= N; ++i){
        for(int j = 0, sz = squares.size(); j < sz; ++j){
            if (dp[i-squares[j]] >= 0)
            dp[i] = min(dp[i-squares[j]] + 1, dp[i]);
        }
    }
    return dp[N];
}

int main(){
    auto value = SumOfSquares(13);
    cout << value << endl;
}
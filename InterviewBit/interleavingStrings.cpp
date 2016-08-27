#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Solution::isInterleave(string A, string B, string C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool dp[A.size()+1][B.size()+1];
    if (A.size() + B.size() != C.size()) return false;
    dp[0][0] = true;
    for (int i = 1; i <= A.size(); ++i) dp[i][0] = C[i-1] == A[i-1];
    for (int i = 1; i <= B.size(); ++i) dp[0][i] = C[i-1] == B[i-1];
    for (int i = 1; i <= A.size(); ++i){
        for(int j = 1; j <= B.size(); ++j){
            dp[i][j] = (C[i+j-1] == A[i-1] && dp[i-1][j]) || (C[i+j-1] == B[j-1] && dp[i][j-1]);
        }
    }
    return dp[A.size()][B.size()];
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Recurse{
unsigned long long N;
int mxDigits;

void generate(unsigned long long number, int digitCount, unsigned long long &mxSoFar){
    if (number > N){
        return;
    }
    mxSoFar = max(number, mxSoFar);
    if (digitCount >= mxDigits) return;
    int lstDigit = number % 10;
    for (int nxtDigit = lstDigit; nxtDigit <= 9; ++nxtDigit){
           generate( number * 10 + nxtDigit, digitCount + 1, mxSoFar);
    }
 }
};

void solve(){
    unsigned long long N;
    cin >> N;
    Recurse recurse = {N, to_string(N).length()};
    unsigned long long mxSoFar = 0;
    for (int i = 1; i <= 9; ++i) recurse.generate(i, 1, mxSoFar);
    cout << mxSoFar << "\n";
}

int main(){
    int t; 
    cin >> t;
    for (int i = 1; i <=t ; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
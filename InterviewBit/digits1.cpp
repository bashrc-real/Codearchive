#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


int solve(string S, int K){
    int N = S.size();
    int ans=0;
    for(int i=0; i+K-1<N; i++) if(S[i]=='0')
    {
        for(int j=0; j<K; j++) S[i+j]^='0'^'1';
        ++ans;
    }

    for(int i=0; i<N; i++) if(S[i]=='0')
    return -1;

    return ans;
}

int main(){
    cout << solve("0001111", 3);
}
// adinfinitumProb1.cpp : Defines the entry point for the console application.
//

#include <set>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <assert.h>

using namespace std;
long long Solve(int N) {
    set<long long> visited;
    for (long long i = 1; i < 10000 ; ++i) {
        long long tmp = i*N;
        while (tmp)
        {
            visited.insert(tmp % 10);
            tmp /= 10;
        }
        if (visited.size() == 10) {
            return i*N;
        }
    }
    assert(false);
}



int main()
{
    ios::sync_with_stdio(false);
    int N;
    int t;
    cin >> t;
   for (int i = 1; i <= t; ++i)
   {
       cin >> N;
        cout << "Case #" << i << ": " << ((N == 0) ? "INSOMNIA" : to_string(Solve(N))) << endl;
   }
    return 0;
}


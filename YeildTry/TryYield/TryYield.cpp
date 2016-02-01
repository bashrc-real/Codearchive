// TryYield.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <experimental\generator>
using namespace std;
using namespace std::experimental;
generator<int> primeSieve(int N) {
  vector<bool> sieve(N + 1);
  for (int i = 3; i <= N; i += 2){
    if (!sieve[i]){
      yield i;
      for (int j = 3 * i; j <= N; j += 2 * i) sieve[j] = true;
    }
  }
 
}
int main()
{
    int sm = 0;
    for (auto iter : primeSieve(3)) {
        sm += iter;
    }
    return 0;
}


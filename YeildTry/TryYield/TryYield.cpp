// TryYield.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <experimental\generator>
using namespace std;
using namespace std::experimental;
generator<int> primeSieve(int N) {
    __yield_value(2);

}
int main()
{
    int sm = 0;
    for (auto iter : primeSieve(3)) {
        sm += iter;
    }
    return 0;
}


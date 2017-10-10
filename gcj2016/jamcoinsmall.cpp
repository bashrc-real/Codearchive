// gcjprob3.cpp : Defines the entry point for the console application.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <assert.h>
using namespace std;

long long checkPrime(long long value) {
    long long ret;
    auto chk = [&ret, value](int val) { auto ans = (val != value) && (value % val == 0); if (ans) ret = val; return ans; };
    if (chk(2) || chk(3) || chk(5) || chk(7) || chk(11)) return ret;
    if (value == 2 || value == 3 || value == 5 || value == 7 || value == 11) return -1;
    for (int i = 2; i <= value / i; ++i) {
        if (value % i == 0) return i;
    }
    return -1;
}

long long convertToBase(uint32_t bits, int base) {
    long long result = 0;
    while (bits) {
        result *= base;
        result += (bits & 1);
        bits >>= 1;
    }
    return result;
}
 long long checkInBase(uint32_t bits, int base) {
    
    return checkPrime(convertToBase(bits,base));
}


auto solve(int N, int J) {
    uint32_t mask = (1 << (N -1)) | 1;
    vector<pair<uint32_t, vector<long long>>> values;
    for (uint32_t bits = 0; bits < (1 << 14); ++bits) {
        uint32_t value = (bits << 1) | mask;
        vector<long long> divisors;
        auto result = checkInBase(value, 2);
        if (result == -1) continue;
        divisors.push_back(result);
        auto result = checkInBase(value, 3);
        if (result == -1) continue;
        divisors.push_back(result);
        divisors.push_back(result * 2);
        auto result = checkInBase(value, 3);
        if (result == -1) continue;
        divisors.push_back(result);
        divisors.push_back(result * 2);

        if (divisors.size() == 9) {
            values.emplace_back(make_pair(value, move(divisors)));
            if (values.size() == J) break;
        }
    }
    return values;
}

auto ToBits(uint32_t value, int N) {
    string result;
    result.resize(N);
    for (int idx = 0; idx <N; ++idx)
    {
        assert(value != 0);
        result[idx] = (value & 1) + '0';
        value >>= 1;
    }
    assert(value == 0);
    return result;
}

void printAndValidate(const vector<pair<uint32_t, vector<long long>>> &vl, int N) {
    for (const auto &V : vl) {
        int cntr = 2;

        assert(V.first & 1 && ((V.first >> (N - 1)) == 1));
        for (auto &V2 : V.second) {
            cout << cntr << ":" << convertToBase(V.first, cntr) << ":" << V2 << endl;
            assert(convertToBase(V.first, cntr) % V2 == 0);
            cntr += 1;
        }
    }
}

int main()
{
    cout << "Case #1:" << endl;
    auto res = solve(32, 500);
    for (const auto &V : res) {
        cout << convertToBase(V.first, 10) << " ";
        for (auto &V2 : V.second) {
            cout << V2 << " ";
        }
        cout << endl;
    }
   // printAndValidate(res, 16);
    return 0;
}


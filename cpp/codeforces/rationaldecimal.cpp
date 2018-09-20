#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

vector<int> getFactors(int N){
    if (N <= 3) return vector<int>{1};
    vector<int> factors;
   for(int i = 2, num = N; i <= num/i; ++i, N = num){
        if(num % i == 0){
            factors.push_back(i);
            if (num / i != i) factors.push_back(num / i);
        }
    }
    factors.push_back(1);
    return factors;
}

bool isRational(const string &str){
    int len = str.length();
    auto factors = getFactors(len);
    int cntr = 0;
    sort(factors.begin(), factors.end());
    for(auto iter = factors.rbegin(); iter != factors.rend(); ++iter){
        auto factor = *iter;
        bool result = true;
        ++cntr;
        for(int i = 0; i < factor && result; ++i){
            for(int j = i + factor; j < len; j += factor, ++cntr){
                if (str[i] != str[j]) { result = false; break; }
            }
        }

        if (result) { return true;}
    }
    return false;
}

// A utility function to fill lps[] or compute prefix funcrion
// used in KMP string matching algorithm. Refer
// https://www.geeksforgeeks.org/archives/11902 for details
void computeLPSArray(const char *str, int M, int lps[])
{
    int len = 0; //lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; //lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (str[i] == str[len])
       {
           len++;
           lps[i] = len;
           i++;
       }
       else // (pat[i] != pat[len])
       {
          if (len != 0)
          {
             // This is tricky. Consider the example AAACAAAA
             // and i = 7.
             len = lps[len-1];
 
             // Also, note that we do not increment i here
          }
          else // if (len == 0)
          {
             lps[i] = 0;
             i++;
          }
       }
    }
}
 
// Returns true if str is repetition of one of its substrings
// else return false.
bool isRepeat(const char *str)
{
    // Find length of string and create an array to
    // store lps values used in KMP
    int n = strlen(str);
    int lps[n];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(str, n, lps);
 
    // Find length of longest suffix which is also
    // prefix of str.
    int len = lps[n-1];
 
    // If there exist a suffix which is also prefix AND
    // Length of the remaining substring divides total
    // length, then str[0..n-len-1] is the substring that
    // repeats n/(n-len) times (Readers can print substring
    // and value of n/(n-len) for more clarity.
    return (len > 0 && n%(n-len) == 0)? true: false;
}
 
int main(){
    string str;
    int passes = 100;
    // Positive passes
   while (--passes){
        int maxLen = 50;
        string str;
        int len = rand() % maxLen + 1;
        for(int i = 0; i < len; ++i) str.push_back(rand() % 10 + '0');
        int actualLen = ((rand() % 100000 + 1)/len) * len;
        if (!actualLen) continue;
        for(int i = len; i < actualLen; ++i) str.push_back(str[i % len]);
        auto start = chrono::high_resolution_clock::now();
        assert(isRational(str) || len == actualLen);
        auto timeDuration = chrono::high_resolution_clock::now() - start;
        auto start2 = chrono::high_resolution_clock::now();
        assert(isRepeat(str.data()) || len == actualLen);
        auto timeDuration2 = chrono::high_resolution_clock::now() - start2; 
        cout << timeDuration.count() << " " << timeDuration2.count()<< endl;
    }

    cout << "Positive passes done" << endl;
    // negative passes
    passes = 100;
    while (--passes){   
        int maxLen = 50;
        string str;
        int len = rand() % maxLen + 1;
        for(int i = 0; i < len; ++i) str.push_back(rand() % 10 + '0');
        int actualLen = ((rand() % 100000 + 1)/len) * len;
        if (!actualLen) continue;
        for(int i = len; i < actualLen; ++i) str.push_back(rand() % 10 + '0');
        auto start = chrono::high_resolution_clock::now();
        assert(!isRational(str));
        auto timeDuration = chrono::high_resolution_clock::now() - start;
        auto start2 = chrono::high_resolution_clock::now();
        assert(!isRepeat(str.data()));
        auto timeDuration2 = chrono::high_resolution_clock::now() - start2;
        cerr << timeDuration.count() << " " << timeDuration2.count()<< endl;
    }

}
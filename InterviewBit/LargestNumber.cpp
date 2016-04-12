

// https://www.interviewbit.com/problems/largest-number/
// Given a list of non negative integers, arrange them such that they form the largest number.
// 
// For example:
// 
// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
// 
// Note: The result may be very large, so you need to return a string instead of an integer.

#include <string>

int countDigits(int number){
    int cntr = 0;
    while (number){
        number/=10;
        ++cntr;
    }
    return cntr;
}

string Solution::largestNumber(const vector<int> &A) {
    map<int, vector<int>> digitsBucket;
    for (auto val : A){
        int dig = countDigits(val);
        string res = to_string(val);
        if (digitsBucket.find(res[0] - '0') == digitsBucket.end()){
            digitsBucket.emplace(res[0] - '0', vector<int>{});
        }
        digitsBucket[res[0] - '0'].push_back(val);
    }
    string result;
    auto append =[](int a, int b) { long long tmp = b; long long T=a; while (b) { b/=10;T*=10;}
    return T + tmp;};
    auto cmp = [append](int a, int b) { return append(a,b) > append(b,a);};
    for (auto dig = digitsBucket.rbegin(); dig != digitsBucket.rend(); ++dig){
        sort(dig->second.begin(), dig->second.end(), cmp);
        for (auto val = dig->second.begin(); val != dig->second.end(); ++val) result += to_string(*val);
    }
    if(digitsBucket.find(0) != digitsBucket.end() && digitsBucket[0].size() ==A.size()) return "0";
    return result;
}

#include<algorithm>
#include <vector>
#include <iostream>
using namespace std;

int longestSumSubArray(vector<int> &arr, int target){
    vector<pair<int, int>> prefixSum;
    prefixSum.reserve(arr.size() + 1);
    prefixSum.emplace_back(0, 0);
    for(int i = 0; i < arr.size(); ++i){
        auto value = prefixSum.back().first;
        prefixSum.emplace_back(value + arr[i], i + 1);
    }

    sort(prefixSum.begin(), prefixSum.end());
    int mxLen = 0;
    for(auto x : prefixSum){
        auto idx = upper_bound(prefixSum.begin(), prefixSum.end(), make_pair(target - x.first, 0));
        if (idx != prefixSum.end() && idx->first == target - x.first){
            mxLen = max(mxLen, abs(x.second - idx->second));
        }
        idx = lower_bound(prefixSum.begin(), prefixSum.end(), make_pair(target - x.first, 0));
        if (idx != prefixSum.end() && idx->first == target - x.first){
            mxLen = max(mxLen, abs(x.second - idx->second));
        }
    }

    return mxLen;
}


int main(){
    int n;
    while(cin >> n){
        vector<int> values;
        int tmp;
        while(n--) {cin >> tmp ; values.push_back(tmp);}
        int target; cin >> target;
        cout << longestSumSubArray(values, target) << endl;
    }
}

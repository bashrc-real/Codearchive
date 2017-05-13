#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <vector>
#include <limits>
using namespace std;

vector<int> getMaxLeft(const vector<int> &vc){
    auto leftMax = vector<int>{numeric_limits<int>::max()};
    leftMax.reserve(vc.size());
    stack<int> keepTrack;
    keepTrack.push(vc[0]);
    for(size_t idx =  1; idx < vc.size(); ++idx){
        while(!keepTrack.empty() && keepTrack.top() <= vc[idx]) keepTrack.pop();
        leftMax.push_back(keepTrack.empty() ? numeric_limits<int>::max() : keepTrack.top());
        keepTrack.push(vc[idx]);
    }
    return leftMax;
}

vector<int> getMaxRight(const vector<int> &vc){
    auto N = vc.size();
    auto rightMax = vector<int>(N, -1);
    rightMax.reserve(vc.size());
    stack<int> keepTrack;
    keepTrack.push(0);
    for(size_t idx =  1; idx < vc.size(); ++idx){
        if (!keepTrack.empty()){
            while(!keepTrack.empty() && vc[keepTrack.top()] <= vc[idx]) { rightMax[keepTrack.top()] = vc[idx]; keepTrack.pop(); }
        }
        keepTrack.push(idx);
    }
    while(!keepTrack.empty()) {rightMax[keepTrack.top()] = numeric_limits<int>::max(); keepTrack.pop();}
    return rightMax;
}


int solve1(const vector<int> &A){
    // cin >> n;
    // vector<int> A(n);
    // for (int i = 0; i < n; ++i) cin >> A[i];
    long long ans = 0;
    auto leftMax = getMaxLeft(A);
    auto rightMax = getMaxRight(A);
    for (int idx = 0; idx < A.size(); ++idx){
        auto l = /*idx == 0 ? numeric_limits<int>::max() :*/ leftMax[idx];
        auto r = /*idx == A.size() - 1 ? numeric_limits<int>::max() :*/ rightMax[idx];
        if (!(l == numeric_limits<int>::max() && r == numeric_limits<int>::max())) ans += min(l, r); 
    }
    return ans;
}

int solve2(const vector<int> &arr){
    int N = arr.size();
    long long ans=0;
    for(int i =0;i<N-1;i++)
    {
        ans+= (long long)max(arr[i], arr[i+1]);        
    }
    return ans;
}

int main(){
    while(true){
    vector<int> A;        
    int N = rand() % 1000 + 1;
    for(int i = 0; i < N; ++i){
        A.push_back(rand() % 10);
    }
    random_shuffle(A.begin(), A.end());
    auto x = solve1(A);
    auto y = solve2(A);
    if (x != y){
        for(auto i : A) {
            cerr << i <<"="<< endl;
        }
        cerr << x << "#" << y << endl;
        return 0;
    }
    }
}

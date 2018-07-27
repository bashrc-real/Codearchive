// Complete the maxDifference function below.
int maxDifference(vector<int> a) {
    if (a.empty()) return -1;

    const int negativeInfinity = -(1 << 29);
    int ans = negativeInfinity;
    int curMin = a[0];
    for(auto x : a){
        curMin = min(curMin, x);
        ans = max(ans, x - curMin);
    }
    return ans == negativeInfinity ? -1 : ans;
}



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(const vector<int> &intervals, const pair<int, int> &interval){
    int high = intervals.size() - 1;
    int low  = 0;
    while (low < high){
        auto midIdx  = (high -  low)/2 + low;
        auto mid = intervals[midIdx];
        if (mid >= interval.first && interval.second < mid){
            return mid;
        }

        if (intervals[mid])


    }
}

vector<int> MergeIntervals(const vector<pair<int,int>> &intervals, const pair<int,int> &interval){
    
}
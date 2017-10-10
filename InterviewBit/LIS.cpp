// We keep track of the current possible length of the subsequence
// algorithm:
//  def LIS(values):
//      heap = []
//      for i in values:
//          add i to heap
//          delete the next greatest element to i from the heap
//      return size(heap)

// The reason why this algorithm works is:
// Lets say the current element is ai  and we have processed elements till i. Count(heap) denotes the current LIS
// if ai is the greatest element seen till now we do not delete anything. Whatever is the current LIS ai will increase that by 1
// else there was some element just greater than ai. Lets say bi. Now both ai and bi cannot be part of the same LIS.
// We have replaced ai with bi which keeps the count of heap as same as before looking at ai. Now it could be possible that
// the element we have removed was part of the bigger subsequence. Since we have replaced it (bi) with a smaller number (ai)
// the LIS will not be effected.

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int LIS(vector<int> const &values)
{
    multiset<int> ordering;
    size_t cntr = 0;
    for (auto val : values)
    {
        ordering.insert(val);
        auto iter = ordering.lower_bound(val);
        ++iter;
        if (iter != ordering.end())
            ordering.erase(iter);
    }
    return ordering.size();
}

int main()
{
    int N;
    cin >> N;
    vector<int> values(N);
    for (size_t idx = 0; idx < N; ++idx)
    {
        cin >> values[idx];
    }
    cout << LIS(values) << endl;
}
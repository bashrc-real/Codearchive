
// https://www.interviewbit.com/problems/inversions/

// Given an array A, count the number of inversions in the array.

// Formally speaking, two elements A[i] and A[j] form an inversion if A[i] > A[j] and i < j

// Example:

// A : [2, 4, 1, 3, 5]
// Output : 3

// as the 3 inversions are (2, 1), (4, 1), (4, 3).

// Solution: (Complexity O(nlogN), space O(N))
// replace the numbers with their rank. (Check the reNumber method)
// for eg {21,12,10} becomes {3,2,1}
// {3,3,3} becomes {1,2,3} (Its important that in case of duplicates the number with higher index value gets a higher rank)
// {2,4,1,3,5} remains same
// Now scan the re-numbered array from the back. Form a BIT while traversing updating the index of the rank with 1.
// At any time the BIT.read(x) will give the number of elements upto x. (Since we are updating each index with value 1.
// Read operation on BIT gives the cumulative result from idx = 0 to x.)
// While traversing also keep updating the count by reading from BIT

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class bit
{
  public:
    bit(int N) : m_bit(N, T{}) {}
    void update(int idx, T value)
    {
        int N = m_bit.size();
        while (idx < N)
        {
            m_bit[idx] += value;
            idx += (idx & -idx);
        }
    }
    T read(int idx)
    {
        T result{};
        while (idx > 0)
        {
            result += m_bit[idx];
            idx -= (idx & -idx);
        }
        return result;
    }

  private:
    vector<T> m_bit;
};

void reNumber(vector<int> &values)
{
    vector<pair<int, int>> indexer;
    indexer.reserve(values.size());
    for (int idx = 0, sz = values.size(); idx < sz; ++idx)
    {
        indexer.emplace_back(values[idx], idx);
    }
    sort(indexer.begin(), indexer.end());
    for (int idx = 0; idx < values.size(); ++idx)
    {
        auto iter = lower_bound(indexer.begin(), indexer.end(), make_pair(values[idx], idx));
        int index = distance(indexer.begin(), iter) + 1;
        values[idx] = index;
    }
}

int countInversions(vector<int> &A)
{
    vector<int> B(A.begin(), A.end());
    int cntr = 0;
    bit<int> Bit(A.size() + 1);
    reNumber(A);
    for (int i = A.size() - 1; i >= 0; --i)
    {
        cntr += Bit.read(A[i] - 1);
        Bit.update(A[i], 1);
    }
    return cntr;
}

#ifdef LOCAL_TESTING
Solution::countInversions(vector<int> &A)
{
    return ::countInversions(A);
}
int main()
{
    vector<int> values{84, 2, 37, 3, 67, 82, 19, 97, 91, 63, 27, 6, 13, 90, 63, 89, 100, 60, 47, 96, 54, 26, 64, 50, 71, 16, 6, 40, 84, 93, 67, 85, 16, 22, 60};
    cout << countInversions(values);
}
#endif
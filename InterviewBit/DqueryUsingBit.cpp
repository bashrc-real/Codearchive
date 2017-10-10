#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T, size_t const maxVal>
class BIT
{
  public:
    BIT()
    {
        m_tree.resize(maxVal);
    }
    void update(int idx, T val)
    {
        while (idx <= maxVal)
        {
            m_tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    T Read(int idx)
    {
        long long sm = 0;
        while (idx > 0)
        {
            sm += m_tree[idx];
            idx -= (idx & -idx);
        }
        return T(sm);
    }

  private:
    vector<T> m_tree;
};

void solve()
{
    int N;
    cin >> N;
    BIT<int, 1000001> distinctCount;
    unordered_set<int> distinctElems;
    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        distinctElems.insert(tmp);
        distinctCount.update(i, distinctElems.size());
    }
    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
    }
}
int main()
{
}
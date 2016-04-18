
//  Implementing LIS using fenwick trees(Binary indexed trees). The idea is to re-number the values to their ranking. 
//  Notice that the renumbering will not effect the actual answer since the relative ordering of the elements remain same.
//  For eg if the array is {10,4,3,11} the renumbered array would be {3,2,1,4}.
//  In case there are duplicates the number with greater index value will have lower rank.
//  for eg for array {2,1,1,3,4} the renumbered array would be {3,2,1,4,5}
//  The same solution will work for longest non-decreasing subsequence by just changing the handling of duplicates to give
//  lower rank to value with lower index value
//  We will use the dynamic programming approach but replace the inner for loop with range queries from the BIT.
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

template <typename T>
class BIT{
    public:
        BIT(size_t N) : m_tree(N, 0), mx(N){}
        void update(int idx, T val){
            while(idx < mx){
                m_tree[idx] = max(m_tree[idx], val);
                idx += (idx & -idx);
            }
        }
        T read(int idx){
           T sm = numeric_limits<T>::min();
           while(idx > 0){
            sm = max(m_tree[idx], sm);
            idx -= (idx & -idx);
           }
           return sm; 
        }
    private:
        vector<T> m_tree;
        size_t mx;
};

int LIS(vector<int> const &values){
    if (values.empty()) return 0;
    int mx = *max_element(values.begin(), values.end());
    BIT<int> bit(mx + 1);
    for (auto val : values){
        bit.update(val, bit.read(val) + 1);
    }
    return bit.read(mx);
}

void reNumber(vector<int> &values){
   vector<pair<int, int>> indexer;
   indexer.reserve(values.size());
   for (int idx = 0, sz = values.size(); idx < sz; ++idx){
       indexer.emplace_back(values[idx], -1*idx);
   }
   sort(indexer.begin(), indexer.end());
   for (int idx = 0; idx < values.size(); ++idx){
       auto iter = lower_bound(indexer.begin(), indexer.end(), make_pair(values[idx], -1*idx));
       int index = distance(indexer.begin(), iter) + 1;
       values[idx] = index;
   }
}
int main(){
    int N;
    cin >> N;
    vector<int> values(N);
    for (size_t idx = 0; idx < N; ++idx){
        cin >> values[idx];
    }
    reNumber(values);
    cout << LIS(values)<<endl;
}
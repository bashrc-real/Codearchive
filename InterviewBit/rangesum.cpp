#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

template <typename T>
class BIT
{
  public:
    BIT(size_t N) : m_tree(N, 0), mx(N) {}
    void update(int idx, T val)
    {
        while (idx < mx)
        {
            m_tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    void update(int l, int r, T v){
        update(l, v);
        update(r+1, -v);
    }

    T read(int idx)
    {
        T sm = 0;
        while (idx > 0)
        {
            sm += m_tree[idx];
            idx -= (idx & -idx);
        }
        return sm;
    }

  private:
    vector<T> m_tree;
    size_t mx;
};

vector<int> solve(int A, const vector<vector<int>> &B){
    auto bit = BIT<int>(A+1);
    for(auto &x : B){
        cerr << x[0] << "@@"<<x[1]<<"@@"<<x[2]<<endl;
        bit.update(x[0],x[1], x[2]);
    }

    vector<int> ans(A);
    for(int idx = 0; idx < A; ++idx){
        ans[idx] = bit.read(idx + 1);
    }
    return ans;
}

void print(const vector<int> &B){
    for(auto x : B) cout << x << " ";
    cout << endl;
}

int main(){
    print(solve(5, {{1,2,4}, {4,5,5}}));
    print(solve(100, {{1,2,100}, {3,100,5}}));
    print(solve(5, {{1,2,10},{2,3,20},{2,5,25}}));

}
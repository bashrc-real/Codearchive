#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class SegmentTree{
    public:
        SegmentTree(int N) : m_tree(N<<1), m_n(N){}
        void update(int idx, int value){
            cerr << "Updating" << idx + m_n << "with value" << endl;
            for(m_tree[idx += m_n] += value; idx > 1; idx >>= 1) {
                m_tree[idx >> 1] = m_tree[idx] + m_tree[idx ^ 1];
                cerr << "updating " << (idx >> 1) << "using" << idx << "and " << (idx^1)<<endl;
            }
            cerr << "===========" << endl;
        }
        
        int  query(int l, int r){
            int res = 0;
            for(l += m_n, r += m_n; l < r; l >>= 1, r >>= 1){
                if (l&1) {
                    cerr << "QQupdating res based on " << l << endl;
                    res += m_tree[l++];
                }
                if (r&1) {
                    res += m_tree[--r];
                    cerr << "QQupdating res based on " << r - 1 << endl;
                }
            }

            cerr << "=============" << endl;
            return res;
        }

    private:
        vector<int> m_tree;
        int m_n;
};


int main(){
    SegmentTree tree(17);
    tree.update(1, 4);
    tree.update(2, 5);
    cout << tree.query(0, 3) << endl;
    cout << tree.query(1, 4) << endl;
    tree.update(4, 10);
    cout << tree.query(0, 4) << endl;
    tree.update(9, 1);
    cout << tree.query(0, 10) << endl;
    tree.update(16, 4);

}
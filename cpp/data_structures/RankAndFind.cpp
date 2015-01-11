#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <array>
#define PR(x) cout<<#x<<"="<<x<<endl
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RP(i,a) for(int i=0;i<a;i++)
#define tr(iter,container) for(auto iter = container.begin();iter!=container.end();iter++) 
#define S(x) cin>>x
#define PRARR(x,n) for(int i=0;i<n;i++) cout<<#x<<"["<<i<<"]= "<<x[i]
#define rd(arr,i,n) for(int i=0;i<n;i++) cin>>arr[i]
#define PB push_back
#define SUM(arr,n,sum) {sum=0;for(int i=0;i<n;i++) sum+=arr[i]; }
#define VC vector
#define CLR(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

template<size_t const N, typename object = size_t>
class RankAndFind{
    public:
        void AddElement(object elem){
           m_parentAndRank[elem].first = elem;
           m_parentAndRank[elem].second = 0;
        }
        object Find(object elem){
            if (elem != m_parentAndRank[elem].first){
                elem = Find(m_parentAndRank[elem].first);
            }
            return elem;
        }
        void Union(object elem1, object elem2){
            object parentLeft = Find(elem1);
            object parentRight = Find(elem2);
            if (parentLeft != parentRight){
                if (m_parentAndRank[parentLeft].second == m_parentAndRank[parentRight].second){
                        m_parentAndRank[parentLeft].first  = parentRight;
                        m_parentAndRank[parentRight].second += 1; 
                }else if (m_parentAndRank[parentLeft].second < m_parentAndRank[parentRight].second) {
                         m_parentAndRank[parentRight].first = parentLeft;
                }else{
                        m_parentAndRank[parentLeft].first = parentRight;        
                }
            }    
        }    
    private:
        array<pair<object,size_t>, N> m_parentAndRank;
};
int main(){
    RankAndFind<10> x;
    x.AddElement(2);
    x.AddElement(3);
    x.AddElement(4);
    x.Union(1,2);
    x.Union(3,4);
    x.Union(2,3);
    cout<<x.Find(1)<<x.Find(4)<<endl;
}


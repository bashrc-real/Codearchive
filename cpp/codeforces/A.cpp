#include <vector>
#include <iostream>
#include <set>
#include <stack>
#include <map>

using namespace std;

template <typename T>
void getFactor(int n, const  T &func){
    int temp = n;
    func(1);
    if (n != 1) func(n);
    for(int i = 2; i <=n/i; i ++){
        if (n % i == 0){
            func(i);
            if (n/i != i) func(n/i);
        }
    }

}

bool getFactors(const vector<int> &origin, const vector<int> &dest, int threshold){
    set<int> factorsOfOrigin;
    for(auto n : origin){
        getFactor(n, [&factorsOfOrigin](int i){
            factorsOfOrigin.insert(i);
        });
    }

    for(auto n : dest){
        getFactor(n, [&factorsOfOrigin, threshold](int i){
            if (i > threshold) factorsOfOrigin.erase(i);
        });
    }

    return factorsOfOrigin.empty() || (*factorsOfOrigin.rbegin() <= threshold);
}

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

vector<set<int>> findComp(const map<int, int> &graph){
    vector<set<int>> components;
    set<int> visited;
    for(auto s : graph){
        auto source = s.first;
        if (visited.find(source) != visited.end()) continue;
        stack<int> dfs;
        set<int> comps;
        dfs.push(source);
        while(!dfs.empty()){
            auto nxt = dfs.top();dfs.pop();
            if (visited.find(nxt) != visited.end()) continue;
            comps.insert(nxt);
            visited.insert(nxt);
            auto iter = graph.find(nxt);
            if (iter != graph.end())
            dfs.push(iter->second);
        }

        components.push_back(move(comps));
    }

    return components;
}

map<int, int> buildGraph(const vector<int> &source, const vector<int> &dest, int q){
   map<int, int> graph;
   for(int i = 0, sz = source.size(); i < sz; ++i){
       if (gcd(source[i], dest[i]) > q) graph[source[i]] = dest[i];
   }

   return graph; 
}
vector<bool> getConnected(const vector<int> &source, const vector<int> &dest, int q){
    auto components = findComp(buildGraph(source, dest, q));
    vector<bool> result(source.size());
    #ifdef FOO
    for(auto &x : components){
        for(auto v : x) cout << v << " ";
        cout << endl << "========="<<endl;
    }
    #endif

    for(int i = 0, sz = source.size(); i < sz; ++i){
        auto city = source[i];
        for(const auto &v : components){
            if (v.find(city) != v.end()){
                result[i] = (v.find(dest[i]) != v.end());
            }
        }
    }

    return result;
}

auto solve(const vector<int> &source, const vector<int> &destination, int q){
    set<int> combined;
    for(auto x : source) combined.insert(x);
    for(auto x : destination) combined.insert(x);
    vector<int> R(source.size());

    for(int i = 0, sz = source.size(); i < sz; ++i){
        auto s = source[i];
        auto d = destination[i];
        bool result = false;
        getFactor(s, [q, d, s, &combined, &result](int f){
            if (f > q){
                long long v = gcd(f, d);
                long long lcm = ((long long)f/(v))*d;
                result |= (combined.find(lcm) != combined.end());
                cout << "###" << f << " "<<q << " "<< " "<< s<<","<<d<<" "<<result << " "<< lcm << endl;
                
            }
        });

        R[i] = result;
    }

    return R;
}

int main(){
    int n;
    cin >> n;
    int q;
    cin >> q;
    int N;
    cin >> N;
    vector<int> origin(N);
    for(int i = 0; i < N; ++i) cin >> origin[i];
    cin >> N;
    vector<int> destination(N);
    for(int i = 0; i < N; ++i) cin >> destination[i];
    auto fc = solve(origin, destination, q);
    for(auto x : fc){ cout << x << " "; }

}
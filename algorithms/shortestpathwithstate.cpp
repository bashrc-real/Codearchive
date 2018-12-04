#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct edge{
    int from;
    int to;
    int cost;
};

int solve(map<pair<int,int>, int> &edges, map<pair<int,int>, int> &flights, int source, int dest, int vertexCount){
    int distance[vertexCount][2];
    for(int i = 0; i < vertexCount; ++i) {distance[i][0] = 1 << 26; distance[i][1] = 1 << 26;}
    distance[source][0] = distance[source][1] =  0;

    for (int i = 0; i < vertexCount; ++i){
        bool earlyBreak = false;
        for(auto &source : edges){
        	int flightCost = 1 << 26;
        	auto from = source.first.first;
        	auto to = source.first.second;
        	auto iter = flights.find(make_pair(from, to));
        	if (iter != flights.end()) flightCost = iter->second;
           distance[to][0] = min(distance[from][0] + source.second, distance[to][0]);
           distance[to][1] = min({distance[to][1], distance[from][0] + flightCost, distance[from][1] + source.second});          
        }
        
        for(auto &source : flights){
        	int roadCost = 1 << 26;
        	auto from = source.first.first;
        	auto to = source.first.second;
        	auto iter = edges.find(make_pair(from, to));
        	if (iter != edges.end()) roadCost = iter->second;
           distance[to][1] = min({distance[to][1], distance[from][0] + source.second, distance[from][1] + roadCost});          
        }
        
    }
    return min(distance[dest][0], distance[dest][1]);
}

int solve2(vector<vector<pair<int, int>>> &edges, vector<vector<pair<int, int>>> &flights, int source, int dest, int vertexCount){
    set<pair<int, pair<int, bool>>> Q;
    const int mx = 1 << 26;
    vector<vector<int>> distance(vertexCount, vector<int>(2, 1<<26));
    distance[source][0] = distance[source][1] = 0;
    for(auto &iter : edges[source]){
        Q.emplace(iter.second, make_pair(iter.first, false));
    }
    for(auto &iter : flights[source]){
        Q.emplace(iter.second, make_pair(iter.first, true));
    }


    while(!Q.empty()){
        auto iter = Q.begin();
        auto value = *iter;
        auto nxt = value.second;
        Q.erase(iter);
        auto prev = distance[value.second.first][0];
        if (!nxt.second){
            for(auto &x : flights[nxt.first]){
                if (distance[nxt.first][0] + value.first < distance[x.first][1]){
                    if(distance[x.first][1] != mx) {
                        Q.erase(Q.find(make_pair(distance[x.first][1],make_pair(x.first, true))));
                    }
                }

                Q.emplace(distance[x.first][1], make_pair(x.first, true));
            }
        }
        for(auto &x : edges[nxt.first]){
            if (distance[nxt.first][0] + value.first < distance[x.first][0]){
                if(distance[x.first][0] != mx) {
                    Q.erase(Q.find(make_pair(distance[x.first][0],make_pair(x.first, false))));
                }
            }

            Q.emplace(distance[x.first][1], make_pair(x.first, false));
            if (distance[nxt.first][1] + value.first < distance[x.first][1]){
                if(distance[x.first][1] != mx) {
                    Q.erase(Q.find(make_pair(distance[x.first][1],make_pair(x.first, true))));
                }
            }

            Q.emplace(distance[x.first][1], make_pair(x.first, true));
        }
    }

    return min(distance[dest][0], distance[dest][1]);
}

int main(){
    int N, P;
    cin >> N >> P;
    map<pair<int,int>, int> graph;
    for(int i = 0; i < P; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        graph.emplace(make_pair(a,b), c);
    }

	int flightEdges;
	cin >> flightEdges;
	map<pair<int,int>, int> flights; 
    for(int i = 0; i < flightEdges; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        flights.emplace(make_pair(a,b),c);
    }
    int source, dest;
    cin >> source >> dest;
    cout << source << "===" << dest <<"===="<<flightEdges << "==="<<N << endl;
    cout << solve(graph, flights, source, dest, N);
}   
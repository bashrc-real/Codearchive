#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int minSteps(const string &source, const string &dest, const set<string> &dict){
    if (source.size() != dest.size()) return -1;
    if (source == dest) return 0;
    int idx = 0;
    queue<string> bfs;
    set<string> visited;
    bfs.emplace(source);
    bfs.emplace("");
    int cntr = 0;
    while(!bfs.empty()){
        auto nxt = bfs.front();bfs.pop();
        if (nxt == dest) break;
        auto iter = visited.find(nxt);
        if (iter == visited.end())
        if (nxt.size() == 0) { ++cntr; continue; }
        for(int i = 0; i < nxt.size(); ++i){
            string tmp = nxt;
            for(int j = 0; j < 26; ++j){
                if (nxt[i] != 'a' + j){
                    tmp[i] = 'a'+j;
                    if (dict.find(tmp) != dict.end()) bfs.push(tmp);
                }
            }
        }

        bfs.push("");
    }

    return cntr;
}


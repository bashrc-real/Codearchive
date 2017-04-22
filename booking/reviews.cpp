#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
string toLower(const string &input){
    string tmp;
    for(auto x : input){
        if (x != '.' && x != ',') tmp.push_back(tolower(x));
        else tmp.push_back(' ');
    }
    return tmp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unordered_set<string> hsh;
    string input;
    getline(cin, input);
    stringstream buffer(input);
    string word;
    while(buffer >> word){
        auto val = toLower(word);
        hsh.insert(val);
    }
    int M;
    cin >> M;
    map<int, int> cntr;
    for(int i = 0; i < M; ++i){
        int id;
        cin >> id;

        string input;
        cin.ignore();
        getline(cin, input);
        string tmp = toLower(input);
     
        stringstream buffer(tmp);
        string inp;
        while(buffer >> inp){
            if (hsh.find(inp) != hsh.end()){
                ++cntr[id];
            }
        }
    }
    for (auto x = cntr.rbegin(); x != cntr.rend(); ++x) cout << x->first << " ";
    cout << endl;
    return 0;
}

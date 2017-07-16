// You are given a set of keywords.
// and a set of reviews for some hotel. Each hotel has a hotel id
// Return the list of hotels sorted in the order of maximum number of words which are in the set of keywords
// for eg: Keywords : ["balcony", "lobby"] 
// and hotel reviews: (in format [hotelId, review])
// [1, "This hotel has a nice balcony and a clean lobby. The balcony overlooks the pool"]
// [2, "random sentence"]
// [3, "good balcony, nice lobby"]
// The output would be [1,3,2]. First hotel(id: 1) has 3 matches (balcony twice and lobby once)
// third hotel has 2 matches (balcony and lobby once each). And the second hotel has no matches

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

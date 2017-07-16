// a website is said good if it is possible to reach it within X clicks starting from the source url.
// each url has a list of websites listed on it. tell whether the website is good or not, given X and the source url.


#include <map>
#include <iostream>
#include <vector>
using namespace std;

bool dfs(const map<string, vector<string>> &urlMap, const string &source, const string &target, int X, int depth){
    if (source == target) return true;
    auto iter = urlMap.end();
    if (X >= depth || (iter = urlMap.find(source)) == urlMap.end()) return false;
    bool result = false;
    for(auto child = iter->second.begin(); !result && child != iter->second.end(); ++child){
        result |= dfs(urlMap, *child, target, X, depth + 1);
    }
    return result;
}
bool isGoodWebsite(const map<string, vector<string>> &urlMap, const string &source, const string &target, int X){
    return dfs(urlMap, source, target, X, 0);
}

int main(){
    
}
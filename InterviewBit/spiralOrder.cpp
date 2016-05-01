#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> directions[4] = {{0, 1}, {1, 0} , {0, -1}, {-1, 0}};

bool validate(int value, const pair<int, int> &bounds){
    return ( (value >= bounds.first) && value < bounds.second);
}

int elemCount(const pair<int, int> &x, const pair<int, int> &y){
    int rows = x.second - x.first;
    int col = y.second - y.first;
    return max(2 *(rows + col - 2), 0);
}

vector<int> SpiralOrder(const vector<vector<int>> &matrix){
    if (matrix.empty()) return vector<int>{};
    if (matrix.size() == 1) return matrix.front();
    pair<int, int> xBounds = {0, matrix.size()};
    pair<int, int> yBounds = {0, matrix[0].size()};
    int dirIdx = 0;
    int cntr = 0;
    vector<int> result;
    result.reserve((matrix.size() * matrix[0].size()));
    pair<int, int> idx{0, 0};
    while ((xBounds.first < xBounds.second) && (yBounds.first < yBounds.second) && validate(idx.first, xBounds) && validate(idx.second, yBounds)){
        result.push_back(matrix[idx.first][idx.second]);
        ++cntr;
        if (cntr >= elemCount(xBounds, yBounds)){
            cntr = 0;
            xBounds.first += 1; xBounds.second -= 1;
            yBounds.first += 1; yBounds.second -= 1;
        }
        auto newIdx = make_pair( idx.first + directions[dirIdx].first, idx.second + directions[dirIdx].second);
        if (!validate(newIdx.first, xBounds) || !validate(newIdx.second, yBounds)){
            dirIdx = (dirIdx + 1) % 4;
            idx = make_pair(idx.first + directions[dirIdx].first, idx.second + directions[dirIdx].second);
        }else{
            idx = move(newIdx);
        }
    }
    return result;
}
int main(){
    auto result = SpiralOrder(vector<vector<int>> {{1},{2},{3}});
    for (auto var : result){
        cout << var << " "<<endl;
    }
}
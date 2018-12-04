#include <vector>
#include <iostream>
using namespace std;
void print(int n){
    vector<vector<char>> buffer(n, vector<char>(2*(n-1) + 1, ' '));
    int spaces = 0;
    int charCount = 2 * (n-1) + 1;
    for(int row = n - 1; row >=0; --row){
        for(int column = spaces, cnt = 0; cnt  < charCount; ++column, ++cnt){
            buffer[row][column] = '*';
        }
        ++spaces;
        charCount -= 2;
    }   

    for(auto &x : buffer){
        for(auto y : x) cout << y;
        cout << endl;
    }
}

int main(){
    int n;
    while(cin >> n) print(n);
}
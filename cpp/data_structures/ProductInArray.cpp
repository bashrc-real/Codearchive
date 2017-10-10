#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int Number(vector<int> &numbers){
    map<int,int> values;
    for(auto v : numbers){
        values[v]+=1;
    }
    sort(numbers.begin(), numbers.end());
    for(auto v = numbers.rbegin(); v != numbers.rend(); ++v){
        int number = *v;
        for (int i = 1; i <= number/i; ++i){
            if (values.find(i) == values.end()) continue;
            if (number%i==0){
                if (values.find(number/i) != values.end()){
                    if (number/i == i) {if(values[i] > 1) return number;}
                    else return number;
                }
                   
            }
        }
    }
    return -1;
}

int main(){
    int N;
    cin >> N;
    vector<int> values(N);
    for(int i = 0; i < N; ++i) cin >> values[i];
    cout << Number(values) << endl;
}

#include "dfs.h"
#include <array>
#include <tuple>
#include <iostream>
bool generate_numbers(int max = 100){
    bool flg = false;
    int value = -1;
    const int pattern = 7;
    dfs(pattern, [&flg, max](int x){ return (x > max) || (flg = (x % 3 == 0)); }, [](int x) { return std::array<int,1>{ x * 10 + pattern }; });
    return flg;
}
int main(){
    std::cout<<generate_numbers(1000)<<std::endl;
}

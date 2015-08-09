#include <iostream>
#include <cstring>

int main(int argc, char **argv){
    // this declaration allows the compiler to optimize away the calls to strlen
    // by a constant value
    const char *const text = "hello";
    std::cout << strlen(text) << std::endl;
    
    // the compiler doesn't optimizes the call to strlen
    char temp[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    std::cout << strlen(temp) << std::endl;
    return 0;
}

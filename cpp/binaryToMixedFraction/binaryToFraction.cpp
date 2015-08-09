#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cassert>

const int max_allowed_digits = 63;

typedef unsigned long long ull;
using namespace std;
void print_error_and_quit(const char * msg){
    std::cerr<<"error:"<<msg<<std::endl;
    exit(-1);
}

ull least_on_bit(ull  u) {
    return ((long long)u) & (-((long long)u));
}

void parse_and_process(const char *dig, ull &quot, ull &rem, ull &div){
    quot = 0 , rem=0, div=1;
    int cntr=0;
    int idx=0;
    while(dig[idx]&&(dig[idx]=='1'||dig[idx]=='0')){
        cntr++;
        if(cntr>max_allowed_digits){
            print_error_and_quit("We are not cool enough to process this large a number :( ");
        }
        quot<<=1ULL;
        quot+=(dig[idx]=='1');
        idx++;
    }

    if(dig[idx]!='.') return;
    idx++;
    cntr = 0;
    while(dig[idx]&&(dig[idx]=='1'||dig[idx]=='0')){
        cntr++;
        if(cntr>max_allowed_digits-1) break;
        rem<<=1ULL;
        rem+=(dig[idx]=='1');
        idx++;
    }
    div = (1ULL)<<cntr;
    while(!(rem&1)){
        rem>>=1;
        div>>=1;
    }   
}

// run as : <exe> <decimal number in base 2>
// output : q (r / d) 
// for eg. ./a.exe 1.111011
// output : 1 (59 / 64)
int main(int argc, char *argv[]){
    if(argc != 2){
        print_error_and_quit("Pass the binary digits as argument");
    }
    
    /* need to print q (r/d) */
    ull q, r, d;
    parse_and_process(argv[1], q, r, d);
    assert(d != 0);
    std::cout<<q;
    if(r!=0){
        std::cout<<"("<<r<<"/"<<d<<")";
    }
    std::cout<<std::endl;
}

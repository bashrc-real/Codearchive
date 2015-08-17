#include <iostream>
class v1{
  public:
          v1(){
              std::cout<<"v1 called"<<std::endl;
          }
          int v;
  private:
    v1 &operator=(const &v1) = delete;
    v1(const &v1) = delete;
};
class v2{
    public:
    v2(){
        std::cout<<"Called"<<std::endl;
    }
    const v1& GetV1() { return foo; }
    v1 foo;
};
int main(){
    v2 bar;
    bar.foo.v= 10;
    auto x = bar.GetV1();
}
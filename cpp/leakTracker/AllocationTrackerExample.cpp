#include "allocation_tracker.h"
#include <memory>

// compiled with TRACK_MEMORY macro defined with the build params
// for eg. in g++ g++ -std=c++11 --pedantic -DTRACK_MEMORY <fileName>
class foo{
    public:
        foo(){
            
        }
    private:
        DECLARE_ALLOC_NAME("foo");    
};
int main(){
    auto x = std::make_shared<foo>();
    auto y = new foo();
}

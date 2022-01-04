/*
struct members and base class/members are all public by default, but you have to explicitly make them private.
class members and base class/members are private by default.
struct and class pointer arithmetic can be confusing as shown below.
*/

#include <cassert>

using namespace std;

struct Foo {
    int x;
};

class Bar {
    private:
        int z;
    public:
        int x;
        int y;
};

int main(void) {
    Foo f;
    assert((void*)&f == (void*)&f.x);
    Bar b;
    assert((void*)&b != (void*)&b.x); // private z pushes x ahead
}


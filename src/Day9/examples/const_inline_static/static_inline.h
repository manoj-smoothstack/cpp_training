#include <cassert>
class A {
    public:
        const static int x = 4; // static can be initialized if const
        A() { assert(x == 4); }; // access inside the class
};

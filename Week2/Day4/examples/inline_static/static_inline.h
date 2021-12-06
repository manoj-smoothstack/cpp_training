#include <cassert>
class A {
    public:
        static int x; // inline inside the class, is public
        A() { assert(x == 4); }; // access inside the class
};
inline int A::x = 4; // if not inline, generates multiple definition of `A::x'

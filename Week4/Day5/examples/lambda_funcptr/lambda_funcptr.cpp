#include <cassert>

int myfunc(int x) { return 2*x; }

int main(void) {
    auto fwd = [](int (*fp)(int), auto a) { return fp(a); };
    assert(fwd(myfunc, 4) == 8);
}


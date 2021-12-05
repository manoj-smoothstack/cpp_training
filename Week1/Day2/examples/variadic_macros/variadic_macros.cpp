#include <cassert>
#define F(...) f(0 __VA_OPT__(,) __VA_ARGS__)
void f(int x, ...) {
    assert(x == 0);
};
int main(void) {
    F(1, 2, 3); // replaced by f(0, 1, 1, 1)
    F();        // replaced by f(0)
}


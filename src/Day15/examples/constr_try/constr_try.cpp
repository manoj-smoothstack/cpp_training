#include <cassert>
void level2() {
    throw 2;
}
class A {
public:
    A() try {
        level2();
    } catch (int e) {
        throw;
    }
};
int main(void) {
    try {
        A a;
    } catch (int e) {
        assert(e == 2);
    }
}


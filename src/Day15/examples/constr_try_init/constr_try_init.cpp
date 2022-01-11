#include <cassert>
  
void level2(int i) {
    throw i;
}

class A {
    int i;
public:
    A(int i) try : i(i) {
        level2(this->i);
    } catch (int e) {
        throw;
    }
};

int main(void) {
    int i = 2;
    try {
        A a(i);
    } catch (int e) {
        assert(e == i);
    }
}


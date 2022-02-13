#include <cassert> 
void level2() {
    throw 2;
}
void level1() try {
    level2();
} catch (int e) {
    throw;
}

int main(void) {
    try {
        level1();
    } catch (int e) {
        assert(e == 2);
    }
}


#include <cassert>

int main(void) {
    int x = 4;
    auto y = [&r = x, x = x + 1]()->int {
            r += 2;
            return x * x;
    }(); // updates ::x to 6 and initializes y to 25.
    assert(x == 6 && y == 25);
}


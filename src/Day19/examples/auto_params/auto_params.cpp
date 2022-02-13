#include <cassert>

int main(void) {
    auto y = [] (auto first, auto second) {
         return first + second;
    };
    assert(y(4, 5) == 9);
}


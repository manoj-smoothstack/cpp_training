#include <cassert>
  
int main(void) {
    auto y = [] (auto first, auto second) -> decltype(first + second) {
         return first + second;
    };
    auto z = [](auto y, auto f, auto s) { return y(f, s); };
    assert(z(y, 4, 5) == 9);
}


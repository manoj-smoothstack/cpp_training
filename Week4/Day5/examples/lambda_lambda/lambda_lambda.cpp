#include <cassert>
  
int main(void) {
    auto fwd = [](int (*fp)(int), auto a) { return fp(a); };
    auto C = [] (auto a) { return a; };
    static_assert(fwd(C, 4) == 4);
}


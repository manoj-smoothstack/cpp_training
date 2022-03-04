#include <type_traits>
#include <cassert>

template<auto I>
struct A {
    decltype(I) i;
};

int main(void) {
    constexpr int x = 2;
    A<(x)> a;
    static_assert(std::is_same_v<decltype(a.i), int>);
}


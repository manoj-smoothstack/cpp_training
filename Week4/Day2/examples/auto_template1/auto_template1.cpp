#include <cassert>
#include <utility>

template<auto n> // C++17 auto parameter declaration
auto f() -> std::pair<decltype(n), decltype(n)> { // auto can't deduce from brace-init-list
    return {n, n};
}

int main(void) {
    auto [v, w] = f<4>();
    assert(v == 4 && w == 4);
    assert(std::make_pair(4, 4) == f<4>()); 
}


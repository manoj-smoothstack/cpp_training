#include <type_traits>

int main(void) {
    //auto l; // error: declaration of variable 'l' with deduced type 'auto' requires an initializer
    auto y = 7;
    auto const z = 8;
    auto int m = 9;
    auto int& n = m;
    static_assert(std::is_same_v<decltype(n), int&>);
    //decltype(auto) const x = 4; //  error: 'decltype(auto)' cannot be combined with other type specifiers
    decltype(auto) x = 4;
}


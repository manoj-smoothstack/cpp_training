#include <type_traits>
#include <cassert>

template <typename T>
auto get_value(T t) {
    if constexpr (std::is_pointer_v<T>)
        return *t; // deduces return type to int for T = int*
    else
        return t;  // deduces return type to int for T = int
}

template <typename T>
bool check(T t) {
    return (get_value(t) == 4);
}

int main(void) {
    float* f_ptr = new float(4);
    float f = 4;
    assert(check(f_ptr));
    assert(check(f));

    bool y = true;
    // if constexpr (y) assert(true); // error: constexpr if condition is not a constant expression

    constexpr bool x = true; 
    if constexpr (x) assert(true);

}



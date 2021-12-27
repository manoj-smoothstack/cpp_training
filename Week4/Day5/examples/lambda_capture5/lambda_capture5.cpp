#include <type_traits>

void f3() {
    float x, &r = x;
    [=]
    { // x and r are not captured (appearance in a decltype operand is not an odr-use)
        decltype(x) y1; // y1 has type float
        static_assert(std::is_same_v<decltype(x), float>);
        decltype((x)) y2 = y1; // y2 has type float const& because this lambda
                               // is not mutable and x is an lvalue
        static_assert(std::is_same_v<decltype(y2), float const&>);
        decltype(r) r1 = y1;   // r1 has type float& (transformation not considered)
        static_assert(std::is_same_v<decltype(r1), float&>);
        decltype((r)) r2 = y2; // r2 has type float const&
        static_assert(std::is_same_v<decltype(r2), float const&>);
    };
}

int main(void) {
    f3();
}


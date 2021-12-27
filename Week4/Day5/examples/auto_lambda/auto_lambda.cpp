#include <cassert>
#include <cstdarg>

int main(void) {
    // auto is commonly used for unnamed types such as the types of lambda expressions
    auto lambda = [](int x) { return x + 3; };
    assert(lambda(4) == 7);

    auto c0 = 10;
    auto c1 = 3;
    [](auto c, auto lambda ...){assert(lambda(c) == 13);}(c0, lambda, c1); // suppresses "unused variable" warnings

    [](auto c, auto lambda ...) {
        assert(lambda(c) == 13);
        va_list args;
        va_start(args, lambda);
        //auto arg = va_arg(args, auto); // error: 'auto' not allowed here
        auto arg = va_arg(args, int);
        assert(lambda(arg) == 6);
    }(c0, lambda, c1); 
}


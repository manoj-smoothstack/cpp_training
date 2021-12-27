#include <cassert>

int main(void) {
    auto f = [](auto a, auto b) -> auto {
        return a * b;
    };
 
    decltype(f) g = f; // the type of a lambda function is unique and unnamed
    auto i = f(2, 2);
    auto j = g(3, 3);
    assert(i == 4 && j == 9);
}


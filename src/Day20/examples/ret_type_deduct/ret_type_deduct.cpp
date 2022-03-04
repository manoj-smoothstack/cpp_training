#include <iostream>

int main() {
    // note: explicitly specifying this returns a double
    auto divide{ [](int x, int y, bool bInteger) -> double {
        if (bInteger)
            return x / y; // will do an implicit conversion to double
        else
            return static_cast<double>(x) / y;
    } };

    std::cout << divide(3, 2, true) << '\n';
    std::cout << divide(3, 2, false) << '\n';
}


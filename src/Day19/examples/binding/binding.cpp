#include <iostream>

int main() {
    auto x = 0, y = 0;
    auto lambda = [x, &y]() { std::cout << x << ' ' << y; };
    x = 1, y = 1;
    {
        x = 27, y = 2;
        lambda();  // still outputs: 0 1
    }
    return 0;
}

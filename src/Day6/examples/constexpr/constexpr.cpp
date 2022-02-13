#include <iostream>

//Note below, sum() is a constexpr function as it’s value is determinable at compile time, as long as the arguments to the sum() call are literals or const.

constexpr int sum(int x, int y) {
    return x + y;
}

int main() {
    const int result = sum(10, 20);     // Here, you can use constexpr as well
    std::cout << result;
    return 0;
}

//Call to the function sum() is not there in assembly. It’s value is substituted at compile time. Constexpr is a way to provide optimization suggestions to the compiler.


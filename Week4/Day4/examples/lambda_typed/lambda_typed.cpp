#include <functional>
#include <cassert>

using namespace std;

int main() {
    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y) { return x + y; };
    assert(f1(2, 3) == 5);

    // Assign the same lambda expression to a function object.
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };
    assert(f1(3, 4) == 7);
}


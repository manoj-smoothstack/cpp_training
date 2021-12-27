#include <algorithm>
#include <array>
#include <cassert>

bool greater(int a, int b) {
    // Order @a before @b if @a is greater than @b.
    return (a > b);
}

int main() {
    std::array arr{ 13, 90, 99, 5, 40, 80 };
    
    // Pass greater to std::sort
    std::sort(arr.begin(), arr.end(), greater);

    std::array sarr{99, 90, 80, 40, 13, 5};
    assert(arr == sarr);
}


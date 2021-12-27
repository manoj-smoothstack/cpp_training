#include <algorithm>
#include <array>
#include <cassert>

int main() {
    std::array arr{ 13, 90, 99, 5, 40, 80 };
    
    // Pass std::greater to std::sort
    std::sort(arr.begin(), arr.end(), std::greater{}); // note: need curly braces to instantiate object

    std::array sarr{99, 90, 80, 40, 13, 5};
    assert(arr == sarr);
}


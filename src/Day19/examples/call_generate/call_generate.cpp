#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int main() {
    // The number of elements in the vector.
    const int elementCount = 9;
    // Create a vector object with each element set to 1.
    vector<int> v(elementCount, 1);
    // These variables hold the previous two elements of the vector.
    int x = 1, y = 1;
    // Sets each element in the vector to the sum of the
    // previous two elements.
    generate_n(v.begin() + 2,
        elementCount - 2,
        [=]() mutable throw() -> int { // lambda is the 3rd parameter
        // Generate current value.
        int n = x + y;
        // Update previous two values.
        x = y;
        y = n;
        return n;
    });
    assert(x == 1 && y == 1);
    vector<int> expv = {1, 1, 2, 3, 5, 8, 13, 21, 34};
    assert(expv == v);
}


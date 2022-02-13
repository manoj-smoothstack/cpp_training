#include <iostream>
#include <cassert>

int main(void) {
    int n = 0;
    for (std::cout << "Loop start\n";
         std::cout << "Loop test\n";
         std::cout << "Iteration " << ++n << '\n')
        if (n > 1)
            break;

    if (std::cout << "hello") 
        assert(true); // no errors happen with this one
    else
        assert(false);
}



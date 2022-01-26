#include <execution>
#include <vector>
#include <iostream>

int main(void) {
    int n = 100;
    std::vector<int> v(n);
    //std::generate(v.begin(), v.end(), [x = 1]() mutable { return ++x;});
    std::atomic<int> count = 0;
    //int count;
    std::for_each(std::execution::par, v.begin(), v.end(), [&](int& x){ x = ++count; });
    for (auto ele: v) {
        std::cout << ele << std::endl;
    }
}


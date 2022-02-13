#include <iostream>
#include <vector>
#include <execution>

int main(void) {
    std::vector<int> v(10);
    int count=0; 
    std::for_each(std::execution::seq, v.begin(),v.end(), [&](int& x){ x=++count; });
    for (auto ele: v) {
        std::cout << ele << std::endl; // order not guaranteed!
    }
}

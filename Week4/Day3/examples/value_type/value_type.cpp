#include <iostream>
#include <vector>
#include <cassert>

template<typename It>
auto add(It begin, It end) -> typename It::value_type {
    typename It::value_type _add{}; 
    _add = *(--end) + (*begin);
    return _add;
}

int main(void) {
    std::vector<int> v = {4, 6, 5, 9};
    assert(add(v.begin(), v.end()) == 13);
}

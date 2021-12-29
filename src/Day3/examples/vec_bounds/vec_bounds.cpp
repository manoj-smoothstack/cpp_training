#include <vector>
#include <cassert>

int main(void) {
    std::vector<int> vec = {2, 4, 5};
    // terminate called after throwing an instance of 'std::out_of_range'
    //what():  vector::_M_range_check: __n (which is 3) >= this->size() (which is 3)
    //assert(vec.at(3) == 0);

    //assert(vec[3] == 0); this does not perform bounds checking
}



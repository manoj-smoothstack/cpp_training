#include <iostream>       // std::cout
#include <set>          // std::set
#include <cassert>
using namespace std;
   
// empty set
int main () {
    set<int> my_empty_set;
    set<int> my_full_set{1,2,3,4};
    assert(*my_full_set.begin() == 1);
}

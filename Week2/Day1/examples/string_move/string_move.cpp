#include <iostream>
#include <string>
#include <cassert>

int main(void) {
    std::string name2 = "Bob"; 
    std::string my_str = std::move(name2);
    assert(name2 == "");
    assert(std::size(name2) == 0);
}


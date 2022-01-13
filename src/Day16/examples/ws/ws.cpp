#include <sstream>
#include <cassert>

int main(void) {
    char c;
    std::istringstream mystr("    end");
    mystr >> std::skipws;
    mystr.get(c);
    assert(c == ' ');
    
    mystr >> std::ws;
    mystr.get(c);
    assert(c == 'e');
}

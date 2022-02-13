#include <iostream>
#include <iomanip>
#include <cassert>

int main(void) {
    std::ostringstream os;
    std::ostringstream cos("");
    cos.copyfmt(os); // saved the format elsewhere
    os << std::setw(4); // sets the context from here on 
    os.copyfmt(cos); // but we reset the context
    os << 7; // can separate on lines
    assert(os.str() == "7");
}


#include <string>
#include <cassert>
 
int main() {
    std::string s1 = "Test";
    //std::string&& r1 = s1;           // error: can't bind to lvalue
 
    //std::string& r2 = s1 + s1; // error: non-const lvalue reference to type 'basic_string<...>' cannot bind to a temporary of type 'basic_string<...>'
    const std::string& r2 = s1 + s1; // okay: lvalue reference to const extends lifetime
    //r2 += "Test";                    // error: can't modify through reference to const
 
    std::string&& r3 = s1 + s1;      // okay: rvalue reference extends lifetime
    r3 += "Test";                    // okay: can modify through reference to non-const
    assert(r3 == "TestTestTest");
}


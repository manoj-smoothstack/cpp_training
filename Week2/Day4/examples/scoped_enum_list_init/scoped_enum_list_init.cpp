#include <cassert>
  
enum byte : unsigned char {}; // byte is a new integer type

void enumfunc(byte b) {
   assert(b = byte{42});
}

// clang++ -std=c++17 -o enum_init  enum_init.cpp
int main(void) {
    byte b {42}; // ok as of c++17
    assert(b == 42);
    byte c {42}; // ok as of c++17
    assert(b == c);
    byte d = byte{42};
    assert(d == b);
    //byte e { -1 }; // error
    struct A { byte b; } s;
    s.b = {43};
    //A a1 = { {42} };  // error: cannot initialize a member subobject of type 'byte' with an rvalue of type 'int'
    A a2 = { byte{ 42 } };  //ok as of c++17
    assert(a2.b == 42);
    assert(a2.b == byte(42));
    //assert(a2.b == {byte(42)}); // error: initializer list cannot be used on the right hand side of operator '=='
    enumfunc(c);
}

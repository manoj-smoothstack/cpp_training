#include <cassert>
#include <iostream>

using namespace std;

int main(void) {
    int* i = new int(2);
    //long l = static_cast<long>(i); // error: static_cast from 'int *' to 'long' is not allowed
    long ll = (long)(i); // c-style cast works fine
    cout << ll << endl;
    //long lll = dynamic_cast<long>(i); // error: invalid target type 'long' for dynamic_cast; target type must be a reference or pointer type to a defined class
    long lll = reinterpret_cast<long>(i);  // this works
    const int c = 4;
    //int cc = const_cast<int>(c); // error: const_cast to 'int', which is not a reference, pointer-to-object, or pointer-to-data-member
    int* cc = const_cast<int*>(&c); // this works
    *cc = 5; // we change the value pointed by cc
    assert(c == 4); // we find that c has not changed, as it's a const
    assert(cc == &c); // we check address of c and cc and they match!
    assert(*cc != c); // so we have the same address but the values do not match
    int nn = 10; // this time nn is not a const
    int* mm = &nn; // mm should contain the address of nn
    *mm = 4; // we change the value at the address pointed
    assert(mm == &nn); // their addresses are same
    assert(nn == 4);  // nn indeed has changed
    assert(*mm == nn); // this time their values match
  
    int& cref = const_cast<int&>(c);
    cref = 5;
    assert(c == 4);
}


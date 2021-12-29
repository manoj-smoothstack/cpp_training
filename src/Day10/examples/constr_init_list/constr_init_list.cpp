#include <iostream>
  
using namespace std;

class X {
    int a, i, j;
public:
    const int& r;

    // The order of constructor initializers is important
    X(int i)
      : a(i) // initializes X::a to the value of the parameter i
      , i(i) // initializes X::i to the value of the parameter i
      , j(this->i) // initializes X::j to the value of X::i 
      , r(a) // initializes X::r to refer to X::a
    { }

    int get_r() { return r; }

    int get_j() { return j; }
};

int main(void) {
    X x(2);
    assert(x.get_r() == 2);
}

//Although using this is not recommended before the start of scope of the constructor body.

#include <string>
#include <utility>
#include <cassert>
 
std::string called;

#define LVAL "lvalue reference overload f"
#define LVAL_CONST "lvalue reference to const overload f"
#define RVAL "rvalue reference overload f"

void f(int& x) {
    called = LVAL;
}
 
void f(const int& x) {
    called = LVAL_CONST;
}

void f(int&& x) {
    called = RVAL;
}
 
int main() {
    int i = 1;
    const int ci = 2;
    f(i);  // calls f(int&)
    assert(called == LVAL);
    f(ci); // calls f(const int&)
    assert(called == LVAL_CONST);
    f(3);  // calls f(int&&)
           // would call f(const int&) if f(int&&) overload wasn't provided
    assert(called == RVAL);
    f(std::move(i)); // calls f(int&&)
    assert(called == RVAL);
 
    // rvalue reference variables are lvalues when used in expressions
    int&& x = 1;
    f(x);            // calls f(int& x)
    assert(called == LVAL);
    f(std::move(x)); // calls f(int&& x)
    assert(called == RVAL);
}


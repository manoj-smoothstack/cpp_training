#include <iostream>
#include <cassert>

struct S2 { void f(int i); };
void S2::f(int i) {
    [=]{i;};          // OK: by-copy capture default
    [=, &i]{i++;};      // OK: by-copy capture, except i is captured by reference
    [=, *this]{i;};   // until C++17: Error: invalid syntax
                    // since c++17: OK: captures the enclosing S2 by copy
    [=, this] {i;};   // until C++20: Error: this when = is the default, warning: explicit capture of 'this' with a capture default of '=' is a C++20 extension [-Wc++20-extensions]
                    // since C++20: OK, same as [=]
    assert(i == 2); // lambda definitions but no executions
}

int main(void) {
    S2().f(2); 
}


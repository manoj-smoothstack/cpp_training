#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cassert>
#include <cstring>

struct A {
    inline static std::stringstream seq;
    int n;
    A(int n = 0): n(n) { A::seq << "A(" << n << ")"; }
    ~A() { A::seq << "~A(" << n << ")"; }
};

int foo() {
    throw std::runtime_error("error");
}

struct B {
    A a1, a2, a3;
    B() try : a1(1), a2(foo()), a3(3) {
        A::seq << "B";
    } catch(...) {
        A::seq << "BException";
    }
    ~B() { A::seq << "~B"; }
};

struct C : A, B {
    C() try {
        A::seq << "C";
    } catch(...) {
        A::seq << "CException";
    }
    ~C() { A::seq << "~C"; }
};

int main () {
    try {
        C c;
    } catch (const std::exception& e) {
        assert(A::seq.str() == "A(0)A(1)~A(1)BException~A(0)CException");
        assert(!strcmp(e.what(), "error"));
    }
}

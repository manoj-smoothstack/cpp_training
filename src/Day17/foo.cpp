#include <iostream>

template <typename T, typename Q>
struct A {
    T amt;
    A(T amt) : amt(amt) {}
    template <typename R>
    A<R, Q> convert() {
        A<R, Q> a(amt);
        return a;    
    }
    template <typename Adder>
    A operator+(const Adder a) {
        A<T, Q> t(amt + a);
        return t;
    }
};

int main(void) {
    A<int, float> a(3);
    A<float, float> a1 = a.convert<float>();
    A<int, float> a2 = a + 4;
}

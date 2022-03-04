#include <cassert>
#include <type_traits>

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class A {
public:
    T value;
    A(T v) : value(v) {}
    T operator ()() { return value; }
    A operator &(const A &a) { return A(value & a.value); }
    A operator |(const A &a) { return A(value | a.value); }
    A operator ^(const A &a) { return A(value ^ a.value); }
    A operator ~() { return A(~value); }
    A& operator &=(const A& a) {
        this->value &= a.value;
        return *this;
    }
    A& operator |=(const A& a) {
        this->value |= a.value;
        return *this;
    }
    A& operator ^=(const A& a) {
        this->value ^= a.value;
        return *this;
    }
};

int main(void) {
    unsigned int x = 7, y = 11; 
    assert((A(x) & A(y))() == (x & y));
    assert((A(x) | A(y))() == (x | y));
    assert((A(x) ^ A(y))() == (x ^ y));
    assert((A(x) &= A(y))() == (x &= y));
    assert((A(x) |= A(y))() == (x |= y));
    assert((A(x) ^= A(y))() == (x ^= y));
    assert(~A(x)() == ~x);
}


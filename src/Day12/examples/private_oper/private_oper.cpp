#include <cassert>

class A {
private:
    int a;
    A operator+(const A& other) { // operator overloads can be private
        return A(this->a + other.a); 
    }
public:
    A(int a) : a(a) {}
    A add(const A& a) {
        return A(*this + a);
    }
    bool operator==(const A& other) {
        return (this->a == other.a);
    }
};

int main(void) {
    A a1(2);
    A a2 = a1.add(a1);
    assert(a2 == A(4));
}

#include <cassert>
#include <typeinfo>
#include <typeindex>

class Base {
public:
    virtual ~Base() = default;
};

class A : public Base { };

int main() {
    A a;
    Base *base = &a;
    Base base1;

    std::type_index ti1(typeid(*base));
    assert(ti1 == std::type_index(typeid(A)));
    std::type_index ti2(typeid(base1));
    assert(ti2 == std::type_index(typeid(Base)));
}

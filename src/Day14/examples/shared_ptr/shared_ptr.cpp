#include <iostream>
#include <memory>
#include <cassert>

int main() {
    int* x1 = new int(42);
    int* x2 = new int(42);
    std::shared_ptr<int> p1(x1);
    std::shared_ptr<int> p2(x2);
    assert(*(p1.get()) == 42);
    auto p3(p1);
    assert(p1 != p2);
    assert(p1 == p3);
    assert(p1.get() == p3.get());
    assert(&p1 != &p3);
}


#include <cassert>
  
template <typename T>
class A {
private:
    T t;
public:
    A(T t) : t(t) {};
    A& operator+(const A& a) {
        this->t += a.getT();
        return *this;
    }
    T getT() const {
        return t;
    }
};

int main() {
    A<int> f1 = {4};
    A<int> f2 = {5};
    A<int> f3 = f1 + f2;
    assert(f3.getT() == 9);
}


#include <cassert>

int main(void) {
    struct X {
        int x, y;
        X(int x, int y) : x(x), y(y) {}
        int operator()(int m) {return m;};
        auto f() {
            // the context of the following lambda is the member function X::f
            return [=]()->int {
                return operator()(this->x + y); // X::operator()(this->x + (*this).y) this has type X*
            };
        }
    };
    X z(2, 5);
    auto lambda = z.f(); // get the lambda from the struct
    assert(lambda() == 7); // call the lambda which uses the function operator
    assert(z(4) == 4); // this of course works, but is trivial
}


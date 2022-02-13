#include <cassert>
  
class A {
    private:
    public:
        inline static int copy;
        A() {};
        A(const A& other) {
            copy++;
        }
};

class B : public A {
    private:
        int y;
    public:
        B() : A() { };
        B(const B& other) {
            copy++;
        }
};

int main(void) {
    B b;
    B b1 = b;
    assert(A::copy == 1);
}


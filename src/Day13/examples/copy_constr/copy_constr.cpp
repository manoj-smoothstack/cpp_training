#include <cassert>
  
class A {
    private:
        int x;
    public:
        inline static int copy;
        A(int x) : x(x) {};
        A(const A& other) {
            copy++;
            x = other.getx();
        }
        int getx() const {return x;};
};

class B : public A {
    private:
        int y;
    public:
        B(int x, int y) : A(x) {
            this->y = y;
        };
        B(const B& other) : A(other) {
            copy++;
            y = other.gety();
        }
        int gety() const {return y;};
};

int main(void) {
    B b(3, 4);
    B b1 = b;
    assert(A::copy == 2);
}


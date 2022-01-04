#include <cassert>

class MyClass {
private:
    int x, y;
public:
     MyClass(int x, int y) {
         this->x = x;
         this->y = y;
     }
     friend int sum(const MyClass&);
};

int sum(const MyClass& mc) {
    return mc.x + mc.y;
}

int main() {
    MyClass mc(2, 5);
    assert(sum(mc) == 7);
}

// Here the friend function is directly called. You need to have a reference to MyClass to do that. 


//This is a class with no name. It cannot have a constructor but does have a destructor. It cannot be passed as an argument to a function.
#include <cassert>
  
class {
    int a;
    public:
        void seta(int a) { this->a = a; };
        int geta() { return a; };
} anon; // multiple objects can be defined here with comma separation.

int main(void) {
    anon.seta(10);
    assert(anon.geta() == 10);
}

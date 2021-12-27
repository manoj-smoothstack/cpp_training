#include <cassert>
#include <string>

class A {
public:
    static std::string called;
    int i;
    A(int i) : i(i) { 
        called += "N";
    }
    A(const A& other) {
        this->i = other.i;
        called += "C";
    }
    ~A() {
        called += "D";
    }
};

inline std::string A::called = "";

int main( ) {
   {
   A::called = "";
   std::pair<int, A> mypair{1, A(1)};
   }
   assert(A::called == "NCDD"); // copy constructor called twice
}


#include <map>
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
   std::map<int, A> m; 
   A::called = "";
   m.insert({1, A{10}});
   }
   assert(A::called == "NCCDDD"); // copy constructor called twice

   {
   std::map<int, A> m; 
   A::called = "";
   m.emplace(1, A{10});
   }
   assert(A::called == "NCDD"); // copy constructor called once
}


#include <type_traits>
#include <cassert>

using namespace std;

struct B {
protected:
   virtual void Foo() {}
};

// Neither trivial nor standard-layout
struct A : B {
   int a;
   int b;
   void Foo() override {} // Virtual function
};

// Trivial but not standard-layout
struct C {
   int a;
private:
   int b;   // Different access control
};

// Standard-layout but not trivial
struct D {
   int a;
   int b;
   D() {} //User-defined constructor
};
struct POD {
   int a;
   int b;
};

int main() {
   assert(!std::is_trivial<A>());
   assert(!std::is_standard_layout<A>());

   assert(std::is_trivial<C>());
   assert(!std::is_standard_layout<C>());

   assert(!std::is_trivial<D>());
   assert(is_standard_layout<D>());

   assert(std::is_trivial<POD>());
   assert(std::is_standard_layout<POD>());
}


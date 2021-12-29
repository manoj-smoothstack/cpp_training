#include <iostream>
#include <cassert>

// declarations can be used as conditions with dynamic_cast
struct Base {
    inline static bool called = false;
    virtual ~Base() {} // we just make the Base polymorphic
};
struct Derived : Base {
    void df() { called = true; }
};

int main(void) {
   Base* bp1 = new Base;
   Base* bp2 = new Derived;
 
   if (Derived* p = dynamic_cast<Derived*>(bp1)) // cast fails, returns nullptr
       p->df();  // not executed
   assert(!Base::called);
 
   if (auto p = dynamic_cast<Derived*>(bp2)) // cast succeeds
       p->df();  // executed
   assert(Base::called);
}


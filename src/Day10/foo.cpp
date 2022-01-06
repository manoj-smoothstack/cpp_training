#include <iostream>

template <class T> struct S {
  operator bool() const;   // conversion function
};

void func(S<int>& s) {
  
  // The compiler converts s to the bool type implicitly through
  // the conversion function. This conversion might be intended.
  if (s) { }
}

void bar(S<int>& p1, S<float>& p2) {
  // The compiler converts both p1 and p2 to the bool type implicitly
  // through the conversion function. This conversion might be unintended. 
  std::cout << p1+p2 << std::endl; 
  
  // The compiler converts both p1 and p2 to the bool type implicitly
  // through the conversion function and compares results. 
  // This conversion might be unintended. 
  if (p1==p2) { }  
}

explicit operator bool() const;

// Error: The call does not match any parameter list for "operator+".
std::cout << p1+p2 << std::endl; 
 
// Error: The call does not match any parameter list for "operator==".
if(p1==p2)

std::cout << bool(p1)+bool(p2) << std::endl; 
if(bool(p1)==bool(p2))

struct T {
  explicit operator bool();   //explicit bool conversion operator
};

int main() {
  T t1;
  bool t2;  
  // The compiler converts t1 to the bool type through 
  // the explicit bool conversion operator implicitly.
  t1 && t2; 
 
  return 0;
}


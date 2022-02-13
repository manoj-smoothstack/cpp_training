#include <cassert>
 
auto make_function(int& x) {
  return [&]{ return x; };
}
 
int main() {
  int i = 3;
  auto f = make_function(i); // the use of x in f binds directly to i
  i = 5;
  assert(f() == 5); // OK; prints 5
}


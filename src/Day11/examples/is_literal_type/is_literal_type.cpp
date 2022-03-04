#include <type_traits>
#include <cassert>

struct A { };
struct B { ~B(){} };

int main() {
  assert(std::is_literal_type<int>::value);
  assert(std::is_literal_type<int&>::value);
  assert(std::is_literal_type<int*>::value);
  assert(std::is_literal_type<A>::value);
  assert(!std::is_literal_type<B>::value);
}


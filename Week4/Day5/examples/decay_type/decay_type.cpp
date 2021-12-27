#include <type_traits>
#include <cassert>

int main() {
  static_assert(std::is_same_v<int, std::decay<int>::type>);
  static_assert(std::is_same_v<int, std::decay<int&>::type>);
  static_assert(std::is_same_v<int, std::decay<int&&>::type>);
  static_assert(std::is_same_v<int, std::decay<const int&>::type>);
  static_assert(std::is_same_v<int*, std::decay<int[2]>::type>);
  static_assert(std::is_same_v<int(*)(int), std::decay<int(int)>::type>);
}


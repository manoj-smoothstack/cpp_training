#include <string_view>
#include <cassert>

int main() {
  char arr[]{ "Gold" };
  std::string_view str{ arr };

  assert(str == arr);

  // Change 'd' to 'f' in arr
  arr[3] = 'f';

  assert(str == "Golf");
}


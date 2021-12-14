#include <cstring>
#include <string_view>
#include <cassert>

int main() {
  std::string_view str{ "balloon" };

  // Remove the "b"
  str.remove_prefix(1);
  // remove the "oon"
  str.remove_suffix(3);
  // Remember that the above doesn't modify the string, it only changes
  // the region that str is observing.

  assert(std::strlen(str.data()) == 6);
  assert(!std::strcmp(str.data(), "alloon"));
  assert(str == "all");
}



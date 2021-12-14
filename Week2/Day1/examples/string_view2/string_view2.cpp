#include <string_view>
#include <cassert>

int main() {
  std::string_view str{ "Peach" };

  // Ignore the first character.
  str.remove_prefix(1);

  assert(str == "each");

  // Ignore the last 2 characters.
  str.remove_suffix(2);

  assert(str == "ea");
}


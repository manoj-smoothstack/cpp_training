#include <algorithm>
#include <array>
#include <string_view>
#include <cassert>

static bool containsNut(std::string_view str) { // static means internal linkage in this context
  // std::string_view::find returns std::string_view::npos, which is a very large number,
  // if it doesn't find the substring.
  // Otherwise it returns the index where the substring occurs in str.
  return (str.find("nut") != std::string_view::npos);
}

int main() {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // std::find_if takes a pointer to a function
    const auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if (found == arr.end()) {
        assert(false);
    } else {
        assert(*found == "walnut");
    }

    return 0;
}


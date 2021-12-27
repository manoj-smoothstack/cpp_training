#include <algorithm>
#include <array>
#include <string_view>
#include <cassert>

int main() {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Define the function right where we use it.
    const auto found{ std::find_if(arr.begin(), arr.end(),
                           [](std::string_view str) { // here's our lambda, no capture clause
                             return (str.find("nut") != std::string_view::npos);
                           }) };

    if (found == arr.end()) {
        assert(false); 
    } else {
        assert(*found == "walnut");
    }
}


#include <algorithm>
#include <array>
#include <cassert>
#include <string_view>

int main() {
    constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    // Count how many months consist of 5 letters
    const auto fiveLetterMonths{ std::count_if(months.begin(), months.end(),
                                       [](std::string_view str) {
                                         return (str.length() == 5);
                                       }) };

    assert(fiveLetterMonths == 2); 
}


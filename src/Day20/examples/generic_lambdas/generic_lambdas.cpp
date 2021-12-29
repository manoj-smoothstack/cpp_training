#include <algorithm>
#include <array>
#include <string_view>
#include <cassert>

int main() {
    constexpr std::array months { // pre-C++17 use std::array<const char*, 12>
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

    // Search for two consecutive months that start with the same letter.
    const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                      [](const auto& a, const auto& b) {
                                        return (a[0] == b[0]);
                                      }) };

    // Make sure that two months were found.
    if (sameLetter != months.end()) {
        // std::next returns the next iterator after sameLetter
        assert(*sameLetter[0] == *std::next(sameLetter)[0]);
    } else assert(false);
}


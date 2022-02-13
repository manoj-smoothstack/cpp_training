#include <iostream>
#include <type_traits>
#include <cstdint>
#include <cassert>
 
int main() {
    // usually true if 'int' is 32 bit
    static_assert(std::is_same<int, std::int32_t>::value); // ~ true
    // possibly true if ILP64 data model is used
    static_assert(!std::is_same<int, std::int64_t>::value); // ~ false
 
    // same tests as above, except using C++17's `std::is_same_v<T, U>` format
    static_assert(std::is_same_v<int, std::int32_t>);  // ~ true
    static_assert(!std::is_same_v<int, std::int64_t>); // ~ false
 
    // compare the types of a couple variables
    long double num1 = 1.0;
    long double num2 = 2.0;
    static_assert(std::is_same_v<decltype(num1), decltype(num2)>); // true
 
    // 'float' is never an integral type
    static_assert(!std::is_same<float, std::int32_t>::value); // false
 
    // 'int' is implicitly 'signed'
    static_assert(std::is_same<int, int>::value);          // true
    static_assert(!std::is_same<int, unsigned int>::value); // false
    static_assert(std::is_same<int, signed int>::value);  // true
 
    // unlike other types, 'char' is neither 'unsigned' nor 'signed'
    static_assert(std::is_same<char, char>::value);          // true
    static_assert(!std::is_same<char, unsigned char>::value); // false
    static_assert(!std::is_same<char, signed char>::value);  // false
 
    // const-qualified type T is not same as non-const T
    static_assert(not std::is_same<const int, int>());
}

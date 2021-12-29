#include <cassert>
#include <type_traits>
 
int main() {
    typedef std::make_signed<unsigned char>::type char_type;
    typedef std::make_signed<unsigned int>::type int_type;
    typedef std::make_signed<volatile unsigned long>::type long_type;
 
    static_assert(std::is_same<char_type, signed char>::value);
    static_assert(std::is_same<int_type, signed int>::value);
    static_assert(std::is_same<long_type, volatile signed long>::value);
} 


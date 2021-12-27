#include <type_traits>
 
class A {};
enum B : int {};
enum class C : int {};
 
int main() {
    static_assert(!std::is_signed<A>::value); // false
    static_assert(std::is_signed<float>::value); // true
    static_assert(std::is_signed<signed int>::value); // true
    static_assert(!std::is_signed<unsigned int>::value); // false
    static_assert(!std::is_signed<B>::value); // false
    static_assert(!std::is_signed<C>::value); // false
 
    // shorter:
    static_assert(!std::is_signed_v<bool>); // false
    static_assert(std::is_signed<signed int>()); // true
    static_assert(!std::is_signed<unsigned int>{}); // false
}


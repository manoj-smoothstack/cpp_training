#include <type_traits>
 
int main() {
    class A {};
 
    static_assert(
           not std::is_pointer<A>::value
        && not std::is_pointer_v<A>   // same thing as above, but in C++17!
        && not std::is_pointer<A>()   // same as above, using inherited operator bool
        && not std::is_pointer<A>{}   // ditto
        && not std::is_pointer<A>()() // same as above, using inherited operator()
        && not std::is_pointer<A>{}() // ditto
        &&     std::is_pointer<A *>::value
        &&     std::is_pointer<A const * volatile>()
        && not std::is_pointer<A &>::value
        && not std::is_pointer<int>::value
        &&     std::is_pointer<int *>::value
        &&     std::is_pointer<int **>::value
        && not std::is_pointer<int[10]>::value
        && not std::is_pointer<std::nullptr_t>::value
    );
}


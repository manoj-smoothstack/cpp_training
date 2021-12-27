#include <type_traits>

const int& getRef(const int* p) { return *p; }
auto getRefFwdBad(const int* p) { return getRef(p); }
decltype(auto) getRefFwdGood(const int* p) { return getRef(p); }
auto getRefFwdGood1(const int* p) -> decltype(getRef(p)) { return getRef(p); }

int main(void) {
    static_assert(std::is_same_v<decltype(getRef), const int&(const int*)>);
    static_assert(std::is_same_v<decltype(getRefFwdBad), int(const int*)>, "Just returning auto isn't perfect forwarding.");
static_assert(std::is_same_v<decltype(getRefFwdGood), const int&(const int*)>, "Returning decltype(auto) perfectly forwards the return type.");
    // Alternatively:
    static_assert(std::is_same_v<decltype(getRefFwdGood1), const int&(const int*)>, "Returning decltype(return expression) also perfectly forwards the return type.");
}


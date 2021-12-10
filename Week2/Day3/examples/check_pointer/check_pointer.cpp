#include <type_traits>
#include <cassert>

template <typename T>
auto is_ptr(T t) {
    return std::is_pointer_v<T>;
}

int main(void) {
    float* f = new float();
    assert(is_ptr<float*>(f));
}

#include <atomic>
#include <cassert>

int main(void) {
    std::atomic_flag myflag(false);
    assert(!myflag.test_and_set());
    assert(myflag.test_and_set());
    myflag.clear();
    assert(!myflag.test_and_set());
    assert(myflag.test()); // C++20 supports test()
}


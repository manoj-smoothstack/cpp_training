#include <atomic>
#include <cassert>

int main(void) {
    std::atomic<bool> b; // false
    assert(!b); // b is false
    bool x = b.load(std::memory_order_acquire);
    assert(!x); // x is false
    b.store(true); // set b to true
    x = b.exchange(false, std::memory_order_acq_rel);
    assert(x && !b); // x is true, b is false
    x = b.exchange(false, std::memory_order_acq_rel);
    assert(!x && !b); // x is false, b is false
    x = b.exchange(false, std::memory_order_acq_rel);
    assert(!x && !b); // x is false, b is false
    x = b.exchange(true, std::memory_order_acq_rel);
    assert(!x && b); // x is false, b is true
    x = b.exchange(true, std::memory_order_acq_rel);
    assert(x && b); // x is true, b is true
    x = b.exchange(false, std::memory_order_acq_rel);
    assert(x && !b); // x is true, b is false
}


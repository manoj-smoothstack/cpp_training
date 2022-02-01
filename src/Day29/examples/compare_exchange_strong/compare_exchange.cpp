#include <atomic>
#include <cassert>

int main(void) {
    bool expected = false;
    bool true_val_to_copy = true;
    bool false_val_to_copy = false;
    std::atomic<bool> b; // b is false
    // since expected matches b, we return true, and copy true_val_to_copy to b, so b becomes true
    assert(b.compare_exchange_strong(expected, true_val_to_copy));
    assert(b); // true is stored in b
    // since expected value is not equal to b, expected now becomes true, and we return false since 
    // expected was not equal to b
    assert(!b.compare_exchange_strong(expected, true_val_to_copy));
    assert(expected); // expected now becomes true
    // since expected (true) is equal to b (true), we return true, and copy false_val_to_copy (false) to b
    // so b becomes false
    assert(b.compare_exchange_strong(expected, false_val_to_copy));
    assert(!b);
}



#include <vector>
#include <thread>
#include <atomic>
#include <cassert>
 
std::atomic<int> cnt = {0};
constexpr int final_counter = 10000;
 
void f() {
    for (int n = 0; n < 1000; ++n) {
        cnt.fetch_add(1, std::memory_order_relaxed);
    }
}
 
int main() {
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f);
    }
    for (auto& t : v) {
        t.join();
    }
    assert(cnt == final_counter);
}


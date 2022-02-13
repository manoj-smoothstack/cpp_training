#include <thread>
#include <vector>

void some_func() {} // called 20 times

auto do_work(unsigned id) {
    return new std::thread(some_func); // thread does not lose scope
}

void f() {
    std::vector<std::thread*> threads;
    for (unsigned i = 0; i < 20; ++i) {
        std::thread *t = do_work(i);
        threads.emplace_back(t);
    }
    for (auto& entry: threads) {
        entry->join();
        delete entry;
    }
}

int main(void) {
    f();
}


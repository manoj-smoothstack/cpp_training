#include <iostream>
#include <memory>
#include <atomic>
#include <string>
#include <thread>

struct Counters { 
    int a;
    int b; 
};

int main() {
/* temporarily comment out
    std::cout << '\n';
    Counters cnt = {3, 6};
    std::atomic<std::shared_ptr<Counters>> counters(
        std::make_shared<Counters>(cnt));
    std::thread t1([&counters] {
        (*counters).a += 1;
        (*counters).b += 1;
        Counters newcnt = {(*counters).a, (*counters).b};
        counters.store(std::make_shared<Counters>(newcnt));
    });
    std::thread t2([&counters] {
        (*counters).a += 1;
        (*counters).b += 1;
        Counters newcnt = {(*counters).a, (*counters).b};
        counters.store(std::make_shared<Counters>(newcnt));
    });
    std::thread t3([&counters] {
        (*counters).a += 1;
        (*counters).b += 1;
        Counters newcnt = {(*counters).a, (*counters).b};
        counters.store(std::make_shared<Counters>(newcnt));
    });
    std::thread t4([&counters] {
        (*counters).a += 1;
        (*counters).b += 1;
        Counters newcnt = {(*counters).a, (*counters).b};
        counters.store(std::make_shared<Counters>(newcnt));
    });
    std::thread t5([&counters] {
        (*counters).a += 1;
        (*counters).b += 1;
        Counters newcnt = {(*counters).a, (*counters).b};
        counters.store(std::make_shared<Counters>(newcnt));
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << *counters.a << *counters.b << '\n';
*/
}

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>
#include <chrono>

// Note that only thread t1 locks mtx. Thread t2 does not lock mtx.
// Hence t1's mtx.lock() does not help us perform a consistent update
// meaning both vuln1 and vuln2 are not consistently set to either 12 each
// or 11 each. Since thread t2 calls vulnerable() that does not lock mtx, it can happen that
// after vuln1 is set to 11 in thread t2, it blocks as thread t1 locks the mtx, and sets both
// vuln1 and vuln2 to 12, and after t1 unlocks the mtx, t2 resumes update
// vuln2 to 11. This happens intermittently and hence also is a race condition.

int vuln1 = 10;
int vuln2 = 10;

struct ele {
    std::string comment;
    std::thread::id id;
};

std::vector<ele> trail;

std::mutex vecmtx;
void vulnerable() { 
    vecmtx.lock();
    ele e1 = {"vulnerable setting", std::this_thread::get_id()};
    trail.push_back(e1);
    vecmtx.unlock();
    vuln1 = 11;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    vuln2 = 11;
    vecmtx.lock();
    ele e2 = {"vulnerable done", std::this_thread::get_id()};
    trail.push_back(e2);
    vecmtx.unlock();
}
void thread_saf() {
    std::mutex mtx;
    mtx.lock();
    vecmtx.lock();
    ele e1 = {"lock thread safe setting", std::this_thread::get_id()};
    trail.push_back(e1);
    vecmtx.unlock();
    vuln1 = 12;
    vuln2 = 12;
    vecmtx.lock();
    ele e2 = {"lock thread safe done", std::this_thread::get_id()};
    trail.push_back(e2);
    vecmtx.unlock();
    mtx.unlock();
}
int main(void) {
    std::thread t1(thread_saf);
    std::thread t2(vulnerable);
    t1.join();
    t2.join(); 
    for (auto ele: trail) {
        std::cerr << ele.comment << ": " << ele.id << std::endl;
    }
    std::cerr << vuln1 << ", " << vuln2 << std::endl; 
}

// one possible output
/*
vulnerable setting: 140429642258176
lock thread safe setting: 140429650650880
lock thread safe done: 140429650650880
vulnerable done: 140429642258176
12, 11
*/

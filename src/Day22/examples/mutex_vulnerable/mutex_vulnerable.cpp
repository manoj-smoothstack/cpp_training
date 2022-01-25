#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>
#include <chrono>

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

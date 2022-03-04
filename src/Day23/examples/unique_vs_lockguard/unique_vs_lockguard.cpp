#include <mutex>

using namespace std;

mutex m;

// only one function can have access to unique_lock
unique_lock<std::mutex>  ufunc(unique_lock<std::mutex> thislock) {
    thislock.unlock(); // unlocked here
    thislock.lock();
    return thislock;
}

// both main and lgfunc have access to thislock as the same time, potential for deadlocks
lock_guard<std::mutex>& lgfunc(lock_guard<std::mutex>& thislock) {
    return thislock;
}

int main(void) {
    unique_lock<std::mutex> mylock(m); // locked here
    mylock = ufunc(std::move(mylock));
    mylock.unlock();
    
    lock_guard<std::mutex> myguard(m);
    lock_guard<std::mutex>& myguard1 = lgfunc(myguard);
}

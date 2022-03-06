#include <mutex>
#include <thread>
#include <cassert>

using namespace std;

mutex m;
int x = 0;
int y = 0;

void func1() {
    unique_lock<mutex> l(m);
    x = 1;
    l.unlock(); // possible to unlock half way through scope
    y = 1;
}

void func2() {
    unique_lock<mutex> l(m);
    x = 2;
    l.unlock();
    y = 2;
}

void func3() {
    lock_guard<mutex> l(m); // cannot unlock this until end of scope
    x = 1;
    y = 1;
}

void func4() {
    lock_guard<mutex> l(m);
    x = 2;
    y = 2;
}

int main(void) {
    for (int i = 0; i < 10000; i++) { // needed 10000 iterations to reproduce 
        thread t1(func1);
        thread t2(func2);
        t1.join();
        t2.join();
        assert(x == y || x != y); // useful if some variables do not need a lock
    }
    for (int i = 0; i < 10000; i++) {
        thread t1(func3);
        thread t2(func4);
        t1.join();
        t2.join();
        assert(x == y); // useful if values of x and y need to be the same
    }
}

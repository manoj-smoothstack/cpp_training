#include <thread>
#include <cassert>
#include <iostream>

void some_function() {}
void some_other_function() {}

int main(void) {
    std::thread t1(some_function);
    std::thread t2 = std::move(t1);
    t1 = std::thread(some_other_function);
    std::thread t3;
    t3 = std::move(t2);
    t1.join(); // 1. if you comment, below line will terminate program
    // t1 = std::move(t3); 2. // This assignment will terminate the program!
    // t1.join(); // 3. Uncomment this if you uncomment 2.
    t3.join(); // 4. Comment this line if you uncomment 2.
}


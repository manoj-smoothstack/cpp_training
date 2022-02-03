#include <iostream>
#include <stdio.h>
#include <thread>

void daemon() {
    for (long double i = 0; i < 9999; i++)
        for (long double j = 0; j < 999; j++);
    std::cout << "end of daemon" << std::endl;
}

int main(void) {
    std::thread t(daemon);
    t.detach();
    std::cout << "detached!" << std::endl;
    // getchar();  // uncomment to test
}

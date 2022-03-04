
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


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

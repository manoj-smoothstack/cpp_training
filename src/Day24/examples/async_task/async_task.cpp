
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <future>
#include <cassert>

int find_the_answer_to_ltuae() { 
    for (long i = 0; i < 44222; i++)
        for (long j = 0; j < 42222; j++);
    return 42; 
}

void do_other_stuff() {}

int main() {
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae); // issue a request, don't wait
    do_other_stuff();
    assert(the_answer.get() == 42);  // this call blocks
}



//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <list>
#include <mutex>
#include <algorithm>
std::mutex some_mutex;

std::list<int> some_list{2, 4, 3, 6, 4, 7};

void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find) {
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(),some_list.end(),value_to_find) != some_list.end();
}

int main(void) {
    if (!list_contains(4)) {
        add_to_list(10);
    }
}



//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <list>
#include <cassert>
#include <algorithm>

template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input) {
    if (input.empty()) {
        return input;
    }
    std::list<T> result; 
    result.splice(result.begin(), input,input.begin());
    T const& pivot=*result.begin();
    auto divide_point = std::partition(input.begin(),input.end(), [&](T const& t){return t<pivot;});
    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(), divide_point);
    auto new_lower(sequential_quick_sort(std::move(lower_part)));
    auto new_higher(sequential_quick_sort(std::move(input)));
    result.splice(result.end(),new_higher);
    result.splice(result.begin(),new_lower);
    return result;
}

int main(void) {
    std::list<int> mylist = {5, 3, 7, 5, 8, 9, 1, 3, 0};
    mylist = sequential_quick_sort(mylist);
    assert(mylist.front() == 0);
}


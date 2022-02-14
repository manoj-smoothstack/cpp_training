
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <mutex>
#include <execution>
#include <iostream>

class X {
    mutable std::mutex m;
    int data;
public:
    X(int x) : data(x) {}
    X(X&& x) {
        this->data = x.data;
    }
    int get_value() const {
        std::lock_guard guard(m);
        return data;
    }
    void increment(){
        std::lock_guard guard(m);
        ++data;
    }
};

void increment_all(std::vector<X>& v){
    std::for_each(std::execution::par, v.begin(), v.end(),
        [](X& x){
            x.increment();
        });
}

int main(void) {
    std::vector<X> vec;
    for (int ii = 0; ii < 100000; ii++) {
        vec.push_back(X(ii));
    }
    increment_all(vec);
}


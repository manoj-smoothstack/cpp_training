#include <mutex>
#include <execution>
#include <iostream>

class Y {
    int data;
public:
    Y(int x):data(x) {}
    Y(Y&& y) {
        this->data = y.data;
    }
    int get_value() const {
        return data;
    }
    void increment() {
        ++data; 
    }
};

class ProtectedY {
    std::mutex m;
    std::vector<Y> v;
public:
    ProtectedY() {
        for (int ii = 0; ii < 100000; ii++) {
            v.push_back(Y(ii));
        }
    }
    void lock() {
        m.lock();
    }
    void unlock() {
        m.unlock();
    }
    std::vector<Y>& get_vec() {
        return v;
    } 
};

void increment_all(ProtectedY& data) {
    std::lock_guard guard(data);
    auto& v=data.get_vec();
    std::for_each(std::execution::par_unseq,v.begin(),v.end(),
        [](Y& y){
            y.increment();
        });
}

int main(void) {
    ProtectedY y{};
    increment_all(y);
}


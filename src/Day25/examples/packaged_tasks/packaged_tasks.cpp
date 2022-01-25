#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>
#include <cassert>
 
// unique function to avoid disambiguating the std::pow overload set
int f(int x, int y) { return std::pow(x,y); }
 
int task_lambda() {
    std::packaged_task<int(int,int)> task([](int a, int b) {
        return std::pow(a, b); 
    });
    std::future<int> result = task.get_future();
 
    task(2, 9);
 
    return result.get();
}
 
int task_bind() {
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();
 
    task();
 
    return result.get();
}
 
int task_thread() {
    std::packaged_task<int(int,int)> task(f);
    std::future<int> result = task.get_future();
 
    std::thread task_td(std::move(task), 2, 10);
    task_td.join();
 
    return result.get();
}
 
int main() {
    assert(task_lambda() == 512);
    assert(task_bind() == 2048);
    assert(task_thread() == 1024);
}



//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


// mutex::lock/unlock
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <chrono>

std::mutex mtx;           // mutex for critical section

void print_thread_id (int id) {
  std::cout << "before lock: thread #" << id << '\n';
  // critical section (exclusive access to std::cout signaled by locking mtx):
  mtx.lock();
  std::cout << "thread #" << id << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  mtx.unlock();
  std::cout << "after unlock: thread #" << id << '\n';
}

int main () {
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_thread_id,i+1);

  for (auto& th : threads) th.join();

  return 0;
}


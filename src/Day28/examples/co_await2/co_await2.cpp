#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>

template<typename PromiseType>
struct GetPromise {
  PromiseType *p_;
  bool await_ready() { return false; } // says yes call await_suspend
  bool await_suspend(std::coroutine_handle<PromiseType> h) {
    p_ = &h.promise();
    return false;     // says no don't suspend coroutine after all
  }
  PromiseType *await_resume() { return p_; }
};

struct ReturnObject3 {
  struct promise_type {
    unsigned value_;

    ReturnObject3 get_return_object() {
      return ReturnObject3 {
        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
  };

  std::coroutine_handle<promise_type> h_;
  operator std::coroutine_handle<promise_type>() const { return h_; }
};

ReturnObject3 counter3() {
  auto pp = co_await GetPromise<ReturnObject3::promise_type>{};

  for (unsigned i = 0;; ++i) {
    pp->value_ = i;
    co_await std::suspend_always{};
  }
}

int main(void) {
  std::coroutine_handle<ReturnObject3::promise_type> h = counter3();
  ReturnObject3::promise_type &promise = h.promise();
  for (int i = 0; i < 3; ++i) {
    std::cout << "counter3: " << promise.value_ << std::endl;
    h();
  }
  h.destroy();
}


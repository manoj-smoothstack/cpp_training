#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>

struct ReturnObject5 {
  struct promise_type {
    unsigned value_;

    ~promise_type() {
      std::cout << "promise_type destroyed" << std::endl;
    }
    ReturnObject5 get_return_object() {
      return {
        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
    std::suspend_always yield_value(unsigned value) {
      value_ = value;
      return {};
    }
    void return_void() {}
  };

  std::coroutine_handle<promise_type> h_;
};

ReturnObject5 counter5() {
  for (unsigned i = 0; i < 3; ++i)
    co_yield i;
  // falling off end of function or co_return; => promise.return_void();
  // (co_return value; => promise.return_value(value);)
}

int main(void) {
  auto h = counter5().h_;
  auto &promise = h.promise();
  while (!h.done()) { // Do NOT use while(h) (which checks h non-NULL)
    std::cout << "counter5: " << promise.value_ << std::endl;
    h();
  }
  h.destroy();
}


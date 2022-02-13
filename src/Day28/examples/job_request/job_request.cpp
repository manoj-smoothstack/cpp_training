#include <coroutine>

struct Job {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>; 
    handle_type coro;
    Job(handle_type h): coro(h){}
    ~Job() { if ( coro ) coro.destroy(); }
    void start() { coro.resume(); }
    struct promise_type {
        auto get_return_object() { return Job{handle_type::from_promise(*this)}; }
        std::suspend_always initial_suspend() { // preparing job
            return {}; 
        }
        std::suspend_always final_suspend() noexcept { // performing job
            return {}; 
        }
        void return_void() {}
        void unhandled_exception() {}
    }; 
};

Job prepareJob() { // return Job helps you find the promise type for this coroutine
    co_await std::suspend_never();
}

int main() {
    auto job = prepareJob();
    job.start();
}


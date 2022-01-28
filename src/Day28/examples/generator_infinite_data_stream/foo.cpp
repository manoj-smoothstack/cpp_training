template<typename T> 
struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;
    Generator(handle_type h): coro(h) {}
    handle_type coro;
    ~Generator() { if ( coro ) coro.destroy(); }
    T getValue() { return coro.promise().current_value; }
    bool next() { 
        coro.resume();
        return not coro.done(); }
    }
    // ...
}


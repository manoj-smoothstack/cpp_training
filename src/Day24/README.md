# Assignment

## Thread-safe queue with try_pop()

Implement a complete example of a thread-safe queue with a calling program
that shows how try_pop() can be used.

Specifically show the use of these methods:

```
 bool try_pop(T& value) {
    std::lock_guard<std::mutex> lk(mut);
    if (data_queue.empty())
        return false;
    value = data_queue.front();
    data_queue.pop();
    return true;
 } 
 std::shared_ptr<T> try_pop() {
    std::lock_guard<std::mutex> lk(mut);
    if (data_queue.empty())
        return std::shared_ptr<T>();
    std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
    data_queue.pop();
    return res;
 }

```

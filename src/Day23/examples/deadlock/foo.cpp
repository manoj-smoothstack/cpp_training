template<typename T,typename Container=std::deque<T> >
class stack {
public:				
    explicit stack(const Container&);
    explicit stack(Container&& = Container());
    template <class Alloc> explicit stack(const Alloc&);
    template <class Alloc> stack(const Container&, const Alloc&); template <class Alloc> stack(Container&&, const Alloc&); 
    template <class Alloc> stack(stack&&, const Alloc&);
    bool empty() const;
    size_t size() const;
    T& top();
    T const& top() const;
    void push(T const&);
    void push(T&&);
    void pop();
    void swap(stack&&);
    template <class... Args> void emplace(Args&&... args);
};

stack<int> s;
if (!s.empty()) { // 1			
    int const value=s.top(); // 2
    s.pop(); // 3
    do_something(value);
}	

std::vector<int> result;			
some_stack.pop(result);	

#include <exception>
#include <memory>
struct empty_stack: std::exception {
    const char* what() const noexcept;
};

template<typename T>
class threadsafe_stack {
public:
    threadsafe_stack();
     threadsafe_stack(const threadsafe_stack&);
     threadsafe_stack& operator=(const threadsafe_stack&) = delete; // 1
     void push(T new_value);
     std::shared_ptr<T> pop();
     void pop(T& value);
     bool empty() const;
};

std::mutex m;
void foo() {
    std::unique_lock<std::mutex> lock(m);
    //m is locked here
    //Protected. Only one thread can be active here.
    //m is unlocked when foo ends
}


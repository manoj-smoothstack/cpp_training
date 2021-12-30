#include <cassert>
#include <utility>
using namespace std;

template <typename T>
class UnsmartPtr {
    T* m_data = nullptr;
public:
    UnsmartPtr(T* data) : m_data(data) {}
    T* operator->() const { return m_data; }
    T operator*() const { return *m_data; }
    T* data() const { return m_data; }
    UnsmartPtr(const UnsmartPtr&) = delete;
    UnsmartPtr& operator=(const UnsmartPtr&) = delete;
    UnsmartPtr& operator=(UnsmartPtr&& other) {
        if (this == &other) return *this;
        cleanup();
        m_data = other.data();
        other.reset();
        return *this;
    }
    UnsmartPtr(UnsmartPtr&& other) {
       cleanup();
       m_data = other.data();
       other.reset();
    }
    ~UnsmartPtr() { 
        cleanup();
    }
    void reset() { m_data = nullptr; }
    explicit operator bool() const noexcept { return m_data != nullptr; };
    void cleanup() { 
        if (m_data != nullptr) {
            delete m_data;
            reset(); 
        }
    }
    void operator delete(void* p) {  // implicitly static member function
        ((UnsmartPtr*)p)->cleanup();
    }
};

class A {
public:
    const int i = 5;
};

int main() {
    {
    A* data = new A();
    UnsmartPtr unsmart_ptr(data);
    assert(unsmart_ptr->i == 5);
    //assert(unsmart_ptr->j == 5); // error: no member named 'j' in 'A'
    assert((*unsmart_ptr).i == 5);
    UnsmartPtr newPtr = std::move(unsmart_ptr);
    unsmart_ptr = std::move(newPtr);
    assert(!newPtr); // calls the bool operator
    } // scope ends and destructors get invoked
}

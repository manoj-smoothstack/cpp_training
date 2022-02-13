#include <memory>
#include <cassert>
 
template<class T>
struct Ptr {
    T* pad; // add pad to compute real address of p
    T* data;
    Ptr(T* arg) : pad(nullptr), data(arg) {
    }
 
    ~Ptr() { delete data; }
    T** operator&() { return &data; }
};
 
int main() {
    int* d = new int(42); // create our data ptr on heap
    Ptr<int> p(d); // we use a wrapper for this pointer
    assert(d == *(&p)); // &p calls operator& and returns address of data in struct
    assert((long)std::addressof(p) == (long)&(p.pad));
}


#include <cassert>
 
template<typename T>
class zero_init {
    T val;
public:
    zero_init() : val(static_cast<T>(0)) { }
    zero_init(T val) : val(val) { }
    operator T&() { return val; }
    operator T() const { return val; }
};
 
int main() {
    zero_init<int> i; assert(i == 0);
    i = 7; assert(i == 7);
    switch(i) { }     // error until C++14 (more than one conversion function)
                      // OK since C++14 (both functions convert to the same type int)
    switch(i + 0) { } // always okay (implicit conversion)
}


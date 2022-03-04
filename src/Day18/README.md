# Assignments

## Implement a Vector template class

Implement a basic vector template class. The rough outline is described below for your benefit. 
Note that the class will not compile as it's just pseudo code for the outline.
It also may have missing methods and intentional mistakes which you may need to correct.
So do not consider this as the final design of your vector class.

```
template<typename T>
class myvector {
private:
    T* mData; // this is the actual data (or array)
	  int mSize; // Size is how much data.  Capacity is how much memory.
	  int mCapacity; // not always same as mSize, usually much larger than mSize.
	  T mUndefined;// Lots of STL functions say that doing something naughty gets "undefined behavior".
public:
    myvector() {}
    myvector(T*, int sz) {} // creates a vector of sz elements
	  virtual ~myvector() {}
	  myvector(const myvector<T>& other) {}
	  myvector(myvector<T>&& other) {}
	  myvector& operator=(const myvector<T>& other) {return nullptr;}
	  bool operator==(const myvector<T>& other) {return false;}
	  T& operator[](int offset) {return false;}
	  void push_back(const T& t) {}
	  void pop_back() {}
	  T& at(int offset) {return nullptr;}
	  void clear() {}
	  int size() const {return 0;}
	  void reserve(int tCount) {} // use an algorithm to increase capacity as required
	  int capacity() const {return mCapacity;}
    // iterator
    class iterator {
        friend myvector;
        myvector* myvec;
        int current; // offset 
    public:
        iterator(myvector* myvec, int offset) {}
        void operator++() {}
        void operator--() {}
        bool operator==(const iterator&);
        bool operator!=(const iterator&);
        T& operator*();
    };
    iterator begin() const {return iterator(nullptr, 0);}; // dummy return
    iterator end() const {return iterator(nullptr, 0);}; // dummy return
};
```

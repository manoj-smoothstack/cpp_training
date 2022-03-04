#include <stdlib.h>
#include <utility>
#include <cassert>
#include <iostream>
template<class T>
class MyArray {
private:
    T *mdata = nullptr;
    int size = 0;
    int buflen = 50;
public:
    MyArray() {
        mdata = new T[buflen];
    }
    MyArray(T t[], size_t len) noexcept(false) {
        mdata = new T[buflen];
        if (len > buflen) throw "Array out of bounds";
        for (int ii = 0; ii < len; ii++, size++) {
            mdata[ii] = t[ii];
        }
    }
    MyArray(MyArray&& other) {
        mdata = other.getMdata();
        size = other.getSize();
        other.setData(nullptr);
        other.setSize(0);
    }
    ~MyArray() { delete [] mdata; mdata = nullptr; size = 0; }
    T& operator[](int index) noexcept(false) {
        if ((size == 0) || (index < 0) || (index > (size-1))) throw "Array out of bounds";
        return mdata[index];
    }
    void push_back(T t) noexcept(false) {
        if (size == buflen) throw "Array out of bounds";
        mdata[size++] = t;
    }
    T& pop_back() { return mdata[size--]; }
    // move assignment
    MyArray& operator=(MyArray&& other) noexcept {
        // Guard self assignment
        if (this == &other)
            return *this;
        delete[] mdata;                               // release resource in *this
        mdata = other.getMdata();
        size = other.getSize();
        other.setMdata(nullptr);
        other.setSize(0);
        return *this;
    }
    T* getMdata() const { return mdata; }
    int getSize() const { return size; }
    void setMdata(T* mdata) { this->mdata = mdata; }
    void setSize(int size) { this->size = size; }
};

int main(void) {
    MyArray<int> myarray;
    myarray.push_back(3);
    assert(myarray.getSize() == 1);
    myarray.push_back(7);
    myarray[0] = 5;
    assert(myarray[1] == 7);
    assert(myarray.getSize() == 2);
    MyArray<int> newarray;
    newarray = std::move(myarray);
    assert(newarray.getSize() == 2);
    newarray.pop_back();
    assert(newarray.getSize() == 1);
    assert(myarray.getSize() == 0);
    size_t len = 20;
    int third[len];
    for (int ii = 0; ii < len; ii++) {
        third[ii] = ii;
    }
    MyArray<int> array20(third, len);
    assert(array20.getSize() == len);
}


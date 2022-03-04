#include <cassert>

class B {
public:
    int z;
    B(int z) { this->z = z; }
};

class A {
public:
    int int_prim;
    int *arr_ptr;
    B *obj_ptr;
    B obj{0};
    A(int int_prim) { this->int_prim = int_prim; }
    void set(int *arr_ptr, B obj, B* obj_ptr) {
        this->arr_ptr = arr_ptr;
        this->obj = obj;
        this->obj_ptr = obj_ptr;
    }
    void setc(int c) { this->obj.z = c; }
};

int main(void) {
    A a1(2); // We create a1 on stack
    A a2 = a1; // The default copy constructor is called
    assert(a2.int_prim == 2); // a2 gets a copy of int_prim 
    a1.int_prim = 5; // we change int_prim in a1
    assert(a2.int_prim == 2); // but the int_prim in a2 is unaffected, that's good!
    int arr[3] = {2, 4, 5}; // first param: array
    B obj(11); // second param of set() function: object
    B *obj_ptr = new B(4); // third_param of set() function: pointer
    a1.set(arr, obj, obj_ptr); // set the values in a1
    a2 = a1; // call default copy constructor again, overwrites a2
    a1.setc(15); // we modify obj to 15 in a1
    assert(a2.obj.z == 11); // a2's obj is still 11, which means B is not shared
    assert(a2.arr_ptr[1] == 4); // a2's array values are same
    a1.arr_ptr[1] = 9; // change an array value in a1
    assert(a2.arr_ptr[1] == 9); // a2 gets the change! arrays are shared between a1 and a2
    assert(a2.obj_ptr->z == 4); // a2's object pointer points to the same value
    a1.obj_ptr->z = 7; // change a1's object pointer to see if a2's object pointer changes
    assert(a2.obj_ptr->z == 7); // a2's value changes! pointer is shared between a1 and a2
}


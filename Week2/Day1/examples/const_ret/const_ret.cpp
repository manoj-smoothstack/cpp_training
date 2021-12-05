// A function may return a const type, but if it is a const primitive type, it makes no sense, although the compiler will allow it. As primitive types cannot be lvalues. However if the return type is a user defined type, it makes sense to return it as a const.
class A {
    public:
        int a;
        void modify() {a++;}; // cannot make this function const either
};

const A constret() {
    return A();
};

int main(void) {
    /*
    const_ret.cpp:13:5: error: 'this' argument to member function 'modify' has type 'const A', but function is not marked const
    constret().modify(); // this line will not compile
    ^~~~~~~~~~
const_ret.cpp:5:14: note: 'modify' declared here
        void modify() {a++;}; // cannot make this function const either
             ^
1 error generated.
make: *** [Makefile:32: const_ret.o] Error 1
    */

    //constret().modify(); // this line will not compile
}

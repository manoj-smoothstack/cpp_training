/*
The first declaration is equivalent to A c = A(1).
If you declare the constructor of the class with the explicit keyword, the previous declarations would be illegal.
For example, if you declare the class as:
*/

class A {  
public:
    explicit A() = default;
    explicit A(int) {};
    explicit A(const char*, int = 0) {};
};

// You can only assign values that match the values of the class type.

int main(void) {
    A a1;
    A a2 = A(1);
    A a3(1);
    A a4 = A("Venditti");
    A* p = new A(1);
    A a5 = (A)1;
    A a6 = static_cast<A>(1);
}

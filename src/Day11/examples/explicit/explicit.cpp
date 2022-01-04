// The explicit function specifier controls unwanted implicit type conversions. It can only be used in declarations of constructors within a class declaration. For example, except for the default constructor, the constructors in the following class are conversion constructors.

class A {  
public:
    A() = default;
    A(int) {};
    A(const char*, int = 0) {};
};

//The following declarations are legal.
int main(void) {
    A c = 1;
    A d = "Venditti";
}


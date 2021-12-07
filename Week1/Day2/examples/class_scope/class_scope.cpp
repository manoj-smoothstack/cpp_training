struct X {
    int f(int a = n) { // n is in scope in function default argument
        return a * n;  // n is in scope in function body
    }
    using r = int;
    r g();
    int i = n * 2; // n is in scope in initializer
//  int x[n]; // error: n is not in scope in class body
    static const int n = 1; // scope of n begins
    int x[n]; // OK: n is now in scope in class body
}; // scope of n pauses
     
struct Y: X { // scope of n resumes
    int y[n]; // n is in scope
}; // scope of n ends
 
//r X::g() {     // error: r is not in scope outside out-of-class function body
auto X::g()->r { // OK: trailing return type r is in scope
    return n;    // n is in scope in out-of-class function body
}

int main(void) {
}

int main(void) {
    if constexpr(false) {
        int i = 0;
        //  error: cannot initialize a variable of type 'int *' with an lvalue of type 'int'
        // int *p = i; // Error even though in discarded statement
    }
}


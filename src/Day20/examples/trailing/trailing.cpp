
//typedef void (*f_arr)(void); // traditional syntax
using f_type = void (void); // syntax with using alias
using f_arrptr = f_type**; // ptr to array of function type

auto g() -> f_arrptr {
    f_arrptr myptr; // uninitialized
    return myptr; // for demonstration only
}

void l() {}

f_type* h() {
    f_type* f = l;
    return f;
}

auto k() -> f_type* {
    f_type* f = l;
    return f;
}

int main(void) {
    auto x = g();
    auto y = h();
}


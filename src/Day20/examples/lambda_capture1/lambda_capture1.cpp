struct S2 { void f(int i); };
void S2::f(int i) {
    [&]{};          // OK: by-reference capture default
    [&, i]{};       // OK: by-reference capture, except i is captured by copy
    //[&, &i] {};   // Error: by-reference capture when by-reference is the default,  error: '&' cannot precede a capture when the capture default is '&'
    [&, this] {};   // OK, equivalent to [&]
    [&, this, i]{}; // OK, equivalent to [&, i]
}

int main(void) {
    S2().f(2);
}


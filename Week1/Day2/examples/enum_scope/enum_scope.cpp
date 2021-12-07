int main(void) {
    enum e1_t { // unscoped enumeration
        A,
        B = A * 2 // A is in scope
    }; // scopes of A and B continue
     
    enum class e2_t { // scoped enumeration
        SA,
        SB = SA * 2 // SA is in scope
    }; // scopes of SA and SB end
     
    e1_t e1 = B; // OK: B is in scope
    //e2_t e2 = SB; // error: SB is not in scope
    e2_t e2 = e2_t::SB; // OK
}


class A {
public:
    int a_member;
    // b_member = 7;   // A does not have access to member functions of B
    class B {
    public:
        // a_member = 4; // B does not have access to member functions of A
        int b_member;
    };
    class C {
    public:
        C() {}
    };
};

int main(void) {}

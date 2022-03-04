struct A {
    int x;
    void modify() const { /*x = 2;*/ }; // cannot assign to non-static data member
};

const A adamant() { return A(); };

int main(void) {
    adamant().modify();
}

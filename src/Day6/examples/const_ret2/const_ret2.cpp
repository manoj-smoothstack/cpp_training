struct A {
    int x;
    void modify() const { x = 2; };
};

const A adamant() { return A(); };

int main(void) {
    adamant().modify();
}

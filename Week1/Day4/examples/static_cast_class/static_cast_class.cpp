class A {
};
class B : A {
};
class C : public A {
};

int main(void) {
    A aa;
    //B bb = static_cast<B>(aa); //error: no matching conversion for static_cast from 'A' to 'B'
    B bb;
    //aa = static_cast<A>(bb); // error: cannot cast 'const B' to its private base class 'const A'
    //C cc = static_cast<C>(aa); // error: no matching conversion for static_cast from 'A' to 'C'
    C cc;
    aa = static_cast<A>(cc); // downward cast is fine
    //cc = aa; // error: no viable overloaded '='
}



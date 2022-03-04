#include <cassert>

class MyExceptionBase {
public:
  virtual void raise();
};

void MyExceptionBase::raise() { throw *this; }

class MyExceptionDerived : public MyExceptionBase {
public:
  virtual void raise();
};
void MyExceptionDerived::raise() { throw *this; }
void f(MyExceptionBase& e) { e.raise(); }

bool catch_called;

void g() {
    MyExceptionDerived e;
    try {
        f(e);
    } catch (MyExceptionDerived& e) {
        catch_called = false;
    } catch (...) {
        catch_called = true;
    }
}

int main(void) {
    try { g; } catch (...) {}
    assert(!catch_called);
}


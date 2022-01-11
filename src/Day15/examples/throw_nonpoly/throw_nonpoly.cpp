#include <cassert>

class MyExceptionBase { };
class MyExceptionDerived : public MyExceptionBase { };
void f(MyExceptionBase& e) {
  throw e;
}
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
    try { g(); } catch (...) {}
    assert(catch_called);
}


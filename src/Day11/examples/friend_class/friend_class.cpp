#include <cassert>

class A; // note we have to forward declare it

class FriendOfA {
public:
    int sum(const A& a); // since A is needed here
    int product(const A& a); // but body goes down to avoid incomplete class error
};

class A {
    friend class FriendOfA; // all methods in FriendOfA have access to private members in A
private:
    int x, y;
public:
    A (int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int FriendOfA::sum(const A& a) { return (a.x + a.y); } // but body of function must be declared separarely
int FriendOfA::product(const A& a) { return (a.x * a.y); } // or else A is an incomplete class

int main(void) {
    FriendOfA friendOfA;
    A a(2, 5);
    assert(friendOfA.sum(a) == 7);
    assert(friendOfA.product(a) == 10);
}


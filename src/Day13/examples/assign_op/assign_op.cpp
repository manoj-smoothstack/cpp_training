/*
 * Account need not implement assign operator.
If it does implement, then you could call the Amount assign operator from the Account assign operator directly.
Each class in the hierarchy can do their own part.
The return from base classes is not processed, as it is always *this.

*/

#include <cassert>
#include <string>

using namespace std;

class Amount {
    private:
        float amt;
    public:
        float getAmt() const { return amt;}
        Amount(float amt) : amt(amt) {};
        Amount operator=(const Amount& other) {
            if (this == &other)
                return *this;
            amt = other.getAmt();
            return *this;
        }
};

class Account : public Amount {
    private:
        string atype;
    public:
        string getAtype() const { return atype; }
        Account(string atype, float amt) : Amount(amt) { };
        // copy assignment
        Account operator=(const Account& other) {
            this->Amount::operator=(other);
            // Guard self assignment
            if (this == &other)
                return *this;

            atype = other.getAtype();
            return *this;
        }
};

int main(void) {
    Account a("checking", 2.85);
    Account a1 = a; // note we need to support this scenario efficiently
    assert(a1.getAtype() == a.getAtype());
    assert(a1.getAmt() == a.getAmt());
}


#include <set>
#include <string>
#include <functional>
#include <cassert>

using namespace std;

class BigObject {
public:
    string id;
    explicit BigObject(const string& s) : id(s) {}
    bool operator< (const BigObject& other) const {
        return this->id < other.id;
    }

    // Other members....
};

inline bool operator<(const string& otherId, const BigObject& obj) { // required for string type
    return otherId < obj.id;
}

inline bool operator<(const BigObject& obj, const string& otherId) { // required for string type
    return obj.id < otherId;
}

int main() {
    // Use C++14 brace-init syntax to invoke BigObject(string).
    // The s suffix invokes string ctor. It is a C++14 user-defined
    // literal defined in <string>
    BigObject b1{ "42F"s };
    BigObject b2{ "52F"s };
    BigObject b3{ "62F"s };
    set<BigObject, less<>> myNewSet; // C++14
    //set<BigObject> myNewSet; // C++14 // less<> is not defined, will not work
    myNewSet.insert(b1);
    myNewSet.insert(b2);
    myNewSet.insert(b3);
    // if less<> and operator<() not overloaded we get, error: no matching member function for call to 'find'
    auto it = myNewSet.find(string("62F"));
    if (it != myNewSet.end())
        assert(it->id == "62F");
    else assert(false);
}


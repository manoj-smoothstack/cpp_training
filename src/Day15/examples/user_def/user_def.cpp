#include <exception>
#include <string>
#include <cassert>

using namespace std;

class UserDemo {
public:
    string error;
    UserDemo(string error) : error(error) {}
};

void user_error() {
    throw UserDemo("user error");
}

int main(void) {
    try {
        user_error();
    } catch (UserDemo& e) {
        assert(e.error == "user error");
    }
}


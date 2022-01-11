#include <exception>
#include <string>
#include <cassert>

class UserError : public std::exception {
    public:
        const char * what() const throw() {
            return "User Error";
        }
};

void user_error() {
    throw UserError();
}

int main(void) {
    try {
        user_error();
    } catch (UserError& e) {
        assert(std::string(e.what()) == "User Error");
    }
}


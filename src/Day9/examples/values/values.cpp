#include <string>

class ValueTypes {
    std::string name;
public:
    ValueTypes(std::string some_name) : name(std::move(some_name)) {
    } 
    std::string& original_name() {
        return name;
    }
    std::string copy_of_name() const {
        return name;
    }
};

int main(void) {
    ValueTypes vt("Mary");
}

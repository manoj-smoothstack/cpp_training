[[noreturn]] void func_with_attr(bool thing2) {
    [[maybe_unused]] bool b = thing2;
    if (!b) {
        return;
    } else {
        throw "error";
    }
}

void func_without_attr(bool thing2) {
    bool b = thing2;
    throw "error";
}

int main() {
    try {
        func_without_attr(true);
    } catch(const char* e) {
    }

    try {
        func_with_attr(true);
    } catch(const char* e) {
    }
}

#include <map>
#include <cassert>
#include <string>

int main(void) {
    std::map<int, std::string> m;
    m.insert(std::pair<int, std::string>(10, "hello"));
    if (auto it = m.find(10); it != m.end()) { 
        assert(it->second.size() == 5);
    }
    if (char buf[10]; std::fgets(buf, 10, stdin)) { m[0] += buf; }
}


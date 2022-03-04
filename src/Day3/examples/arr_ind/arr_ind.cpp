#include <cassert>

int main(void) {
    unsigned short usmallint = static_cast<unsigned short>(10);
    int us[usmallint];
    signed short smallint = static_cast<signed short>(10);
    int s[smallint];
    signed char schar = static_cast<char>(10);
    int sc[schar];
    signed long slong = static_cast<signed long>(10);
    int sl[slong];
}

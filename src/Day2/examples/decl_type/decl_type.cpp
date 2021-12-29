#include <iostream>
#include <cassert>

using namespace std;
 
int main(void) {
    double d;
    int i;
    char c;
    char double_type = typeid(d).name()[0];
    char int_type = typeid(i).name()[0];
    char char_type = typeid(c).name()[0];

    string inp;
    cout << "Enter type (double, int, char): ";
    while (cin) {
        cin >> inp;
        if (inp[0] == double_type) 
            cout << sizeof(double);
        else if (inp[0] == int_type) 
            cout << sizeof(int);
        else if (inp[0] == char_type)
            cout << sizeof(char);
        cout << endl;
        cout << "Enter type (double, int, char): ";
    }
    cout << endl;
}

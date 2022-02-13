#include <iostream>
using namespace std;
void showprecision(float ff, int precision) {
    cout.precision(precision);
    cout << "Precision " << precision << ": " << ff << endl;
}
int main(void) {
    float xx = 3.6;
    showprecision(xx, 5);
    showprecision(xx, 7);
    showprecision(xx, 8);
    showprecision(xx, 20);
}

//Precision 5: 3.6
//Precision 7: 3.6
//Precision 8: 3.5999999
//Precision 20: 3.5999999046325683594

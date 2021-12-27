#include <iostream>
#include <functional>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

checked_uint1024_t factorial(int n) { 
    std::function<checked_uint1024_t(int)> fac;
    fac = [&fac](int n){return (n < 2) ? 1 : n * fac(n-1); };
    return fac(n);
};

int factorial2(int n) { 
    std::function<int(int)> fac;
    fac = [&fac](int n) {return n < 2 ? 1 : n * fac(n - 1); };
    return fac(n);
};

int main(void) {
    assert(factorial(170) == checked_uint1024_t("7257415615307998967396728211129263114716991681296451376543577798900561843401706157852350749242617459511490991237838520776666022565442753025328900773207510902400430280058295603966612599658257104398558294257568966313439612262571094946806711205568880457193340212661452800000000000000000000000000000000000000000"));
    assert(factorial2(11) == 39916800);
}

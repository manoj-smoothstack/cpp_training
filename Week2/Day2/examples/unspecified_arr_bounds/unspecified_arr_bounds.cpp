#include <string>
#include <cassert>

static std::string called;

void myoverload(int myarr[]) {
    called = "int";
} 

//void myoverload(int myarr[10]) {} //  error: redefinition of 'myoverload'
//void myoverload(int* myarr) {} //  error: redefinition of 'myoverload'

void myoverload(short myarr[]) {
    called = "short";
} 

void myoverload(unsigned int myarr[]) {
    called = "unsigned int";
} 

void myoverload(const unsigned int myarr[]) {
    called = "const unsigned int";
} 

int main(void) {
    myoverload(new int[10]); // calls void myoverload(int myarr[])
    assert(called == "int");
    myoverload(new unsigned int[10]); // calls void myoverload(unsigned int myarr[])
    assert(called == "unsigned int");
    //myoverload(new unsigned short[10]); //  error: no matching function for call to 'myoverload'
    myoverload(new const unsigned int[10]{1}); // calls void myoverload(const unsigned int myarr[])
    assert(called == "const unsigned int");
}


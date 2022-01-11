#include <string>
#include <future>

struct X {
    void foo(int,std::string const&) {}
    std::string bar(std::string const&) { return ""; }
};


struct Y {
    double operator()(double) { return 0; }
};

class move_only {
public:
    move_only() {};
    move_only(move_only&&) { };
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&) {return *this;};
    move_only& operator=(move_only const&) = delete;
    void operator()() {};
};

X baz(X& x) {return x; }

int main(void) {
    X x;
    auto f1=std::async(&X::foo,&x,42,"hello");
    auto f2=std::async(&X::bar,x,"goodbye");
    Y y;
    auto f3=std::async(Y(),3.141);
    auto f4=std::async(std::ref(y),2.718);
    auto f6=std::async(baz, std::ref(x));
    auto f5=std::async(move_only());
    
    auto f10=std::async(std::launch::async,Y(),1.2); 
    auto f7=std::async(std::launch::deferred,baz, std::ref(x));
    auto f8=std::async(std::launch::deferred | std::launch::async, baz, std::ref(x));
    auto f9=std::async(baz,std::ref(x)); 
    f7.wait();
}



template <typename T, typename Q, typename C>
class Account {
private:
    T amt;
public:
    Account(T a): amt(a) {}
    T deposit(T& a); // returns balance
    T withdraw(T& a);  // returns balance
    Q convert(C c); // calls func object c to convert to currency Q
};

int main(void) {}

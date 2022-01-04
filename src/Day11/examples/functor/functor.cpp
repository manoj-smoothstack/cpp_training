class Functor {
public:
    int operator() (int a, int b) {
        return a < b;
    }
};

int main() {
    Functor f;
    int a = 5;
    int b = 7;
    int ans = f(a, b);
}


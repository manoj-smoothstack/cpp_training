/*
A default constructor is added if there are no constructors defined in the class by the user (unless it is deleted).
You have learnt that you can prevent the compiler from creating a default constructor, by creating a dummy private constructor.
The dummy private constructor can never be invoked from outside the class unless we have friends, and hence a nameless person object cannot be created, as long as you do not have friends.
A default constructor always has no parameters, and will not throw any exceptions or have any other attributes.
A private constructor can be used in singletons or factory patterns, where a static method can call a private constructor.
 */
class Object {
private:
    int id;
    // private constructor, not for general use
    explicit Object(int i) : id(i) { }
public:
    static Object createWithID(int id) {
        return Object(id);
    }
};
int main() {
    Object obj1 = Object::createWithID(1);
}

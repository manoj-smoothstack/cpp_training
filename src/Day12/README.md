# Assignments

## Overloading string operators

Implement your own string class MyString and overload at least 3 operators, + and \* and [].

```
MyString s = "abc"
assert((s + s) == "abcabc");
assert((s * 3) == "abcabcabc"); // works mostly like python * operator
assert(s[2] == 'c');
assert((s + 1) == "bc"); // s+1 returns an rvalue temporary that can be compared with "bc"
```

You should not derive from std::string. Work with C style strings and create a wrapper.

## Other special functions

In the above assignment, implement:

- Copy/Move constructors
- Copy/Move assignment operators
- Regular constructors/destructor

You do not need to implement other string functions.

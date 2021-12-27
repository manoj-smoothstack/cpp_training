#include <functional>   // std::function, std::plus, std::minus
#include <cassert>

int my_plus (int a, int b) {return a+b;}
int my_minus (int a, int b) {return a-b;}

int main () {
  std::function<int(int,int)> foo = my_plus; // function template with local function
  std::function<int(int,int)> bar = std::plus<int>(); // function template with std function

  assert(foo(100, 20) == (*foo.target<int(*)(int,int)>())(100,20)); // comparing direct execution with target execution
  assert(bar(100, 20) == (*bar.target<std::plus<int>>())(100,20)); // // comparing direct execution with target execution

  *foo.target<int(*)(int,int)>() = &my_minus; // changing target directly
  assert(foo(100, 20) == 80); // testing after change
}


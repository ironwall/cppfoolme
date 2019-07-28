#include <iostream>
#include <type_traits>
#include <functional>
using namespace std;

int add(int a){
  return a;
}
template<class A, class B, class...Args>
int add(A a, B b, Args...args){
    return a+add(b, args...);
}
template<class A, class B>
int add(A a, B b){
    return a+b;
}

int add2(int a,  int b){
  return a+b;
}

int main()
{
    cout << add(1, 2, 3, 5) << endl;  //=> 11 
    cout << add(1, 2) << endl;       //=> 3
    cout << std::invoke(add2, 1, 3) << endl; //ok => 4
    cout << std::invoke(add, 1, 3) << endl; //no
    cout << std::invoke(add, 1, 3, 4, 5) << endl; //no
}


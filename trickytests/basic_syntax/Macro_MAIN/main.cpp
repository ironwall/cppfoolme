// Actually, if you want to write tests, 
// the better choice is googletest
// This just is a joke XD


#include <iostream>
using namespace std;
#ifndef MAIN
#define MAIN
//------------
#include "a.cpp"
#include "b.cpp"
//------------
int main(){
  A a;
  B b;

  cout<<a.foo(b)<<endl;
  cout<<b.foo(a)<<endl;
}
#endif

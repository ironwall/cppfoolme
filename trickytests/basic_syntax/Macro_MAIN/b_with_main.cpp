#ifndef B_CPP
#define B_CPP
#include "b.h"
#include "a.h"
#include <iostream>
using namespace std;
int B::bar(){
  return data;
}
int B::foo(A& a){
  return a.bar();
}
#ifndef MAIN
#define MAIN
#include "a_with_main.cpp"
int main(){
  A aa;
  cout<<aa.bar()<<endl;
}
#endif
#endif

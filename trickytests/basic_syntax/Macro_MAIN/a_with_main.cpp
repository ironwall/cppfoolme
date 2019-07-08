#ifndef A_CPP
#define A_CPP
#include "a.h"
#include "b.h"
#include <iostream>
using namespace std;
int A::bar(){
  return data;

}
int A::foo(B& b){
  return b.bar();
}
#ifndef MAIN
#define MAIN
#include "b_with_main.cpp"
int main(){
  B bb;
  cout<<bb.bar()<<endl;
}
#endif
#endif

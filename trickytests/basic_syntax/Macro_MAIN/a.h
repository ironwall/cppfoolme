#ifndef A_H
#define A_H
#include "a.h"
class B;
class A{
  private:
    int data;
  public:
    A(){
      data = 1;
    }
    int bar();
    int foo(B& b);
};
#endif

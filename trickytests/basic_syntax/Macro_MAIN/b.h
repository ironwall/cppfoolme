#ifndef B_H
#define B_H
#include "a.h"
class A;
class B{
  private:
    int data;
  public:
    B(){
      data = 0;
    }
    int bar();
    int foo(A& a);
};
#endif

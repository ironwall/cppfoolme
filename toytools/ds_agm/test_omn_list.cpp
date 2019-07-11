#include <iostream>
#include <string>

#include "omnipotent_list.hpp"

int main(){
  list a;
  list b;
  b.prepend("b is a sub-list");
  b.prepend(4);
  a.prepend(b);
  a.prepend(1);
  a.prepend(2.2);
  a.prepend("this is a string");
  a.display();
}

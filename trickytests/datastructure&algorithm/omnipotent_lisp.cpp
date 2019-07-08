#include <iostream>
#include <string>
class node{
  public:
    node *next;
    virtual void display() = 0;
};
template<class T>
class _node_ : public node{
  public:
    T data;
    _node_(T a){
      data = a;
    }
    void display() override{
      std::cout << data;
    }
};
class list{
  public:
    list(){head = nullptr;}
    template<class T> void prepend(T a){
        node *temp = new _node_<T>(a);
        temp -> next = head;
        head = temp;
    }
    void display(){
      node *temp = head;
      while(temp){
        temp->display();
        printf("->");
        temp = temp -> next;
      }
      printf("\n");
    }
    node *head;
};
template<>
class _node_<list> : public node{
  public:
    list data;
    _node_(list a){
      data = a;
    }
    void display() override{
      std::cout << "sublist: ";
      data.display();
    }
};
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

#ifndef OMNIPOTENT_LIST_HPP
#define OMNIPOTENT_LIST_HPP

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
    #ifdef DEBUG
    void display() override{
      std::cout << data;
    }
    #endif
};
class list{
  private:
    node *head;
  public:
    list(){head = nullptr;}
    template<class T> void prepend(T a){
        node *temp = new _node_<T>(a);
        temp -> next = head;
        head = temp;
    }
    #ifdef DEBUG
    void display(){
      node *temp = head;
      while(temp){
        temp->display();
        printf("->");
        temp = temp -> next;
      }
      printf("\n");
    }
    #endif
};
template<>
class _node_<list> : public node{
  public:
    list data;
    _node_(list a){
      data = a;
    }
    #ifdef DEBUG
    void display() override{
      std::cout << "sublist: ";
      data.display();
    }
    #endif
};
#endif

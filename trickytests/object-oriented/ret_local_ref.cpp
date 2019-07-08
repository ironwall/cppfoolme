#include <iostream>
#include <string>
#include <utility>
using namespace std;

class A{
public:
    int num;
    A(int c){num = c;}
    A& temp(){
        A tmp(1);
        return tmp;
    }
    void set_num(int num){
        this->num = num;
    }
    void display(){
        cout<<num<<endl;
    }
};
int main()
{
    
    A s(2);
    A &test = s.temp();
    A &&test2 = std::move(s.temp());
    s.temp().num = 4;           //本质上是做大死
    s.temp().display();
    s.temp().set_num(4);    //本质上是做大死
    s.temp().display();
    test.set_num(4);
    test.display();
    test.num = 5;
    test.display();
    test2.set_num(4);
    test2.display();
    test2.num = 5;
    test2.display();
    /*
     */
}


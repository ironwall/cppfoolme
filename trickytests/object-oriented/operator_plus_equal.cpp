// Example program
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class A{
public:
    int num;
    //friend A operator+(const A& a, const A& b);
    A(){}
    A(int a){num=a;}
    A(const A& cp){
        cout<<"copy constructor: ";
        num = cp.num + 2;
    }
    A(const A&& cp){
        cout<<"move constructor: ";
        num = cp.num - 99;
    }
//    A& operator-(const A&a){
//        A tmp;
//        tmp.num = this->num - a.num;
//        //return std::move(tmp);
//        return tmp;
//    }

    A& operator=(const A&a){
        /*if(&a == this)
            return *this;*/
        cout<<"= overload : ";
        num = a.num + 100;
        return *this;
    }
    A operator+(const A& a){
        A c;
        c.num = this->num + a.num;
        return c;
    }
};
/*A operator+(const A& a, const A& b){
    A tmp;
    tmp.num = a.num + b.num;
    return tmp;
}*/
int main()
{
    A a,b;
    a.num = 3;
    b.num = 4;
    //----------------
    A &&c = a + b; cout<< "c"<<endl;
    A &&c2 = std::move(a); cout<< "c2"<<endl;
    A d = a + b; cout<< "d"<<endl;
    A d2 = a; cout<< "d2"<<endl;
    A e;
    e = a + b; cout<< "e"<<endl;
    A f(a + b); cout<< "f"<<endl;
    A f2(std::move(a + b)); cout<< "f2"<<endl;
    
//    A g = a - b;            //问题在这
//    A &&g2 = std::move(a - b);
//    A h;
//    h = a - b;
    cout<<c.num<<endl;      //7 使用了&&，并未调用拷贝构造函数
    cout<<c2.num<<endl;     //3 使用了move+&&，没有调用拷贝构造函数
    cout<<d.num<<endl;      //7 并未调用拷贝构造函数
    cout<<d2.num<<endl;     //5 调用了拷贝构造函数，
    cout<<e.num<<endl;      //107 调用了=重载
    cout<<f.num<<endl;      //7 同d
    cout<<f2.num<<endl;     //k移动语义构造函数
    //-------------------------到此为止大部分编译器都是一致的
//    cout<<g.num<<endl;      //垃圾值,??
//    cout<<g2.num<<endl;     //另一个垃圾值
//    cout<<h.num<<endl;      //99(正确）3 - 4 + 100,调用了=重载 [[有些编译器仍会是垃圾值
    
    /*
     A operator+(const A& a, const A& b){
         A c;
         c.num = a.num + b.num;
         return c;
     }
     A& operator = (const A&a){
         this -> num = a.num + 1;
         return *this;
     }
     
     */
}

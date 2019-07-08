#include <iostream>
#include <memory>
using namespace std;

class A{
public:
    int num[100];
public:
    A(){
        memset(num, 0, sizeof(num));
        cout << "Construct" << endl;
    }
    A(const A& obj){
        memcpy(num, obj.num, sizeof(num));
        cout << "Copy Construct" << endl;
    }
    A& operator=(const A& obj){
        memcpy(num, obj.num, sizeof(num));
        cout << "operator =" << endl;
        return *this;
    }
    ~A(){
        cout << "Destructor" << endl;
    }
};
A getobj1(){
    A a;
    a.num[0] = 1;
    return a;
}
A getobj3(A& obj){
    obj.num[0] = 1;
    return obj;
}

A& getobj_r1(){
    A a;
    a.num[0] = 2;
    return a;
}
void getobj_r2(A &obj){
    obj.num[0] = 2;
}
A& getobj_r3(A& obj){
    obj.num[0] = 2;
    return obj;
}
int main(){
    //A &&p = ge:tobj1();
    //A *p = getobj3();
    cout<<"********************"<<endl;
    
    cout<<"TEST#1"<<endl;
    A test1 = getobj1();
    cout<<test1.num[0]<<endl;
    cout<<"********************"<<endl;
    
    cout<<"TEST#3"<<endl;
    A test3 = getobj3(test3);
    cout<<test3.num[0]<<endl;
    cout<<"********************"<<endl;
    
    cout<<"========================================"<<endl;
    
    cout<<"********************"<<endl;
    cout<<"TEST#r1:1"<<endl;
    A testr1_1 = getobj_r1();
    cout<<testr1_1.num[0]<<endl;
    cout<<"--------"<<endl;
    cout<<"TEST#r1:2"<<endl;
    A testr1_2;
    testr1_2 = getobj_r1();
    cout<<testr1_2.num[0]<<endl;
    cout<<"********************"<<endl;
    
    cout<<"TEST#r2"<<endl;
    A testr2;
    getobj_r2(testr2);
    cout<<testr2.num[0]<<endl;
    cout<<"********************"<<endl;
    
    cout<<"TEST#r3:1"<<endl;
    A testr3_1 = getobj_r3(testr3_1);
    cout<<testr3_1.num[0]<<endl;
    cout<<"--------"<<endl;
    cout<<"TEST#r3:2"<<endl;
    A testr3_2;
    testr3_2 = getobj_r3(testr3_2);
    cout<<testr3_2.num[0]<<endl;
    cout<<"********************"<<endl;
    
    /* result:
     ********************
     TEST#1
     Construct
     1
     ********************
     TEST#3
     Copy Construct
     1
     ********************
     ========================================
     ********************
     TEST#r1:1
     Construct
     Destructor
     Copy Construct
     2
     --------
     TEST#r1:2
     Construct
     Construct
     Destructor
     operator =
     2
     ********************
     TEST#r2
     Construct
     2
     ********************
     TEST#r3:1
     Copy Construct
     2
     --------
     TEST#r3:2
     Construct
     operator =
     2
     ********************
     Destructor
     Destructor
     Destructor
     Destructor
     Destructor
     Destructor
     Destructor
     */
    
    return 0;
}

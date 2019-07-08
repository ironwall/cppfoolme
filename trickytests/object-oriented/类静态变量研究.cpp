#include <iostream>
using namespace std;
#define  init(typeName,className,variableName,value) typeName className::variableName = value
//宏替换和内联函数仍旧有区别，此处可以体现，静态成员变量初始化不可以在任何函数内 
class myClass{
public:
	static int i;
	int geti(){return i;}
	static seti(int a){i=a;}
	static getis(){cout<<"i:"<<i<<endl;}
};

init(int,myClass,i,0);

int main(){
	myClass::getis();
	myClass::seti(1);
	myClass::getis();
	
	myClass a;
	
	cout<<"a.geti():"<<a.geti()<<endl;
	a.seti(2);
	a.getis();
	
	myClass *b=&a;
	
	cout<<"b->geti():"<<b->geti()<<endl; 
	a.seti(3);
	b->getis();
	return 0;
}

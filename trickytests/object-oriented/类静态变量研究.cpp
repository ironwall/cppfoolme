#include <iostream>
using namespace std;
#define  init(typeName,className,variableName,value) typeName className::variableName = value
//���滻�����������Ծ������𣬴˴��������֣���̬��Ա������ʼ�����������κκ����� 
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

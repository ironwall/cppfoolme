#include <iostream>
using namespace std;

class A{
public:
	void setx(int a){this->a=a;}
	int getx(){return a;}
private:
	int a;
};

void change1(A b){
	b.setx(2);
	cout<<"b.getx"<<b.getx()<<endl;
}

void change2(A &b){
	b.setx(3);
} 
void change3(A *b){
	b->setx(4);
} 
int main(){
	A a;
	a.setx(1);
	cout<<a.getx()<<endl;
	change1(a);
	cout<<a.getx()<<endl; 	//copy�ķ�ʽ��
	
	change2(a);
	cout<<a.getx()<<endl; 	//�����óɹ� 
	
	change3(&a);
	cout<<a.getx()<<endl;	//��ָ��Ҳ�ɹ� 
}

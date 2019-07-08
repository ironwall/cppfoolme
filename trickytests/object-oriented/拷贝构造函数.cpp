#include <iostream>
using namespace std;

class Point{
public:
	Point(){};
	Point(int a,int b){x=a,y=b;}
	Point(const Point &p){x=2*p.x,y=2*p.y;}	//	�������캯�� 
	void print(){cout<<x<<" "<<y<<endl;}
private:
	int x,y;
};

//***************************** 
void func1(Point p){
	p.print();
} 
void func2(Point *p){
	p->print();
}
void func3(Point &p){
	p.print();
}
Point* funcx1(Point p){
	return &p;
}
Point funcx2(Point p){
	return p;
}
//***************************** 

Point func4(){
	Point p(10,30);
	return p;
}
Point *func5(){
	Point *p = new Point(10,30);
	return p;
}

int main(){
	Point p1(30,40);
	p1.print();
	
	Point p2(p1);	//����Point p2=p1; 
	p2.print();
	
	cout<<endl;
	func1(p1);		//ֻ�ں����ڲ��о���һ�ο������캯�� 
	func2(&p1);		//ָ�������ȫ�ƹ����캯�� 
	func3(p1);		//����Ҳ������ȫ�ƹ� 
	Point *pp=funcx1(p1);	//����2��
	func2(pp);
	p1=funcx2(p1);			//����4�� �βο���һ�Σ�����ֵ����һ��
	func3(p1);
	cout<<endl;
	
	Point p4;		//��û�е��ÿ������캯�� û�е��ÿ������캯������Ϊcopy elision
	p4=func4();
	p4.print(); 
	
	Point *p5;		//ͬ��û�� 
	p5=func5();
	p5->print(); 
	return 0;
} 

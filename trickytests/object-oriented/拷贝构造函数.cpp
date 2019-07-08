#include <iostream>
using namespace std;

class Point{
public:
	Point(){};
	Point(int a,int b){x=a,y=b;}
	Point(const Point &p){x=2*p.x,y=2*p.y;}	//	拷贝构造函数 
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
	
	Point p2(p1);	//或者Point p2=p1; 
	p2.print();
	
	cout<<endl;
	func1(p1);		//只在函数内部有经过一次拷贝构造函数 
	func2(&p1);		//指针可以完全绕过构造函数 
	func3(p1);		//引用也可以完全绕过 
	Point *pp=funcx1(p1);	//翻了2倍
	func2(pp);
	p1=funcx2(p1);			//翻了4倍 形参拷贝一次，返回值拷贝一次
	func3(p1);
	cout<<endl;
	
	Point p4;		//并没有调用拷贝构造函数 没有调用拷贝构造函数是因为copy elision
	p4=func4();
	p4.print(); 
	
	Point *p5;		//同样没有 
	p5=func5();
	p5->print(); 
	return 0;
} 

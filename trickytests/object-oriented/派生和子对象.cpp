#include <iostream>
using namespace std;

class suba{
public:
	suba(int set){x = set;}
	int x;
};
class A{
public:
	suba b;
	int a;
	A(int set):b(set){a = set;}
};

class B:public A{
public:
	int q; 
	suba c;
	B(int a,int b,int c):A(a),c(b){this->q=c;}
}; 
int main(){
	
	B b(1,2,3);
	cout<<"b.q  "<<b.q<<endl;
	cout<<"b.b.x  "<<b.b.x<<endl;
	cout<<"b.c.x  "<<b.c.x<<endl;
	cout<<"b.a  "<<b.a<<endl;

}

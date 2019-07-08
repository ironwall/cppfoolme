#include <iostream>
#include <typeinfo.h>
using namespace std;

typedef int funcclass(int);

int f(int a, int b, funcclass *pf){
	return pf(a+b);
} 

int square(int x){
	return x*x;
}

int add(int a,int b){
	return a+b;
}
int main(){
	cout<<f(1,2,&square);
	cout<<add(add(1,2),3);
} 

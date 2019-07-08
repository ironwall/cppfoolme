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
int f2(int n);
void wrapper(int n, funcclass *f);

int f2(int n){
    if(n==1)
        wrapper(2,&f);
    else
        return n;
}
void wrapper(int n, funcclass *f){
    f(n+1);
}

int main(){
	cout<<f(1,2,&square);
	cout<<add(add(1,2),3);
    cout<<f2(1);
} 

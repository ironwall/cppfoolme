#include <iostream>
#include <typeinfo.h>
using namespace std;

typedef int funcclass(int);

int f(int n);
void wrapper(int n, funcclass *f);

int f(int n){
	if(n==1)
		wrapper(2,&f);
	else
		return n;
}

void wrapper(int n, funcclass *f){
	f(n+1);
}

int main(){
	cout<<f(1);
} 

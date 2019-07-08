#include <iostream>
using namespace std;

int main(){
	const char *name = "a";
	cout<<name<<endl;
	name="bb";
	cout<<name<<endl;	//指向常量的指针，可以改变指针所指向的常量
	
	char ch[20]="ccc";
	char *const name2 = ch; //不能直接 char *const name2 = "ccc"; char const name2[20]与 const char *name类似，是指向常量的指针 
	cout<<name2<<endl;
	cout<<name2[1]<<endl; 
	name2[1]='d';
	cout<<name2<<endl;	//常指针，可以改变指向的量的值
	 
	const char * const name3="sss";//指向常量的指针 
	cout<<name3<<endl;
	return 0;
} 

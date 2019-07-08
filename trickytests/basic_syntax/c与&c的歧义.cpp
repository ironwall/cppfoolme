#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char b[]="321";
	printf("b数组的地址是(printf ) 0x%x\t\n",b); 
	cout<<"b数组的地址是(int *直接转换) \t"<<(int *)b<<endl;
	cout<<"b数组的地址是(&b)  \t"<<&b<<endl;
	void *np=b;
	cout<<"b数组的地址是(用空指针再转换)\t"<<(int *)np<<endl;
	cout<<"b数组的地址是(无法输出地址)\t"<<&b[0]<<endl;
	
	int c[10]={1,2};
	cout<<endl<<"数组c的地址是(c)\t"<<c<<endl;
	cout<<"数组c的地址是(&c)\t"<<&c<<endl;		
	cout<<"数组c的地址是(&c[0])\t"<<&c[0]<<endl<<endl;  //c和 &c &c[0]  输出结果的一样的 
	
} 

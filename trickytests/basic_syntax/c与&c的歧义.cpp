#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char b[]="321";
	printf("b����ĵ�ַ��(printf ) 0x%x\t\n",b); 
	cout<<"b����ĵ�ַ��(int *ֱ��ת��) \t"<<(int *)b<<endl;
	cout<<"b����ĵ�ַ��(&b)  \t"<<&b<<endl;
	void *np=b;
	cout<<"b����ĵ�ַ��(�ÿ�ָ����ת��)\t"<<(int *)np<<endl;
	cout<<"b����ĵ�ַ��(�޷������ַ)\t"<<&b[0]<<endl;
	
	int c[10]={1,2};
	cout<<endl<<"����c�ĵ�ַ��(c)\t"<<c<<endl;
	cout<<"����c�ĵ�ַ��(&c)\t"<<&c<<endl;		
	cout<<"����c�ĵ�ַ��(&c[0])\t"<<&c[0]<<endl<<endl;  //c�� &c &c[0]  ��������һ���� 
	
} 

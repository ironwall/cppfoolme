#include <iostream>
using namespace std;

int main(){
	const char *name = "a";
	cout<<name<<endl;
	name="bb";
	cout<<name<<endl;	//ָ������ָ�룬���Ըı�ָ����ָ��ĳ���
	
	char ch[20]="ccc";
	char *const name2 = ch; //����ֱ�� char *const name2 = "ccc"; char const name2[20]�� const char *name���ƣ���ָ������ָ�� 
	cout<<name2<<endl;
	cout<<name2[1]<<endl; 
	name2[1]='d';
	cout<<name2<<endl;	//��ָ�룬���Ըı�ָ�������ֵ
	 
	const char * const name3="sss";//ָ������ָ�� 
	cout<<name3<<endl;
	return 0;
} 

#include <iostream>
using namespace std;

int main(){
	char name[6][3]{"11",
					"22",
					"33",
					"55",
					"66",
					"77"};
	char (*p)[3]=name;		//��p����ÿ��������3 
	char *p2[6];
	p2[0]=name[0];
	cout<<p2[0];
	//p2[0]�����������Ϊ��ֵ�����
	//p2[1]������� 
	cout<<*(p+5);//Ҳ����д��  p[5]	
} 

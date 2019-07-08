#include <iostream>
using namespace std;

int main(){
	char name[6][3]{"11",
					"22",
					"33",
					"55",
					"66",
					"77"};
	char (*p)[3]=name;		//第p个，每个不超过3 
	char *p2[6];
	p2[0]=name[0];
	cout<<p2[0];
	//p2[0]可以输出，因为赋值完毕了
	//p2[1]不能输出 
	cout<<*(p+5);//也可以写成  p[5]	
} 

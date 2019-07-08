//引用不是数据类型 
#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

int &max(int &num1,int &num2){
	return (num1>num2)?num1:num2;
}
int *min(int *num1,int *num2){
	return (*num1<*num2)?(num1):(num2);
}
int main(){
	int i=5;
	int j=6;
	int &ri=i;
	int &rj=j;
	swap(ri,rj);
	cout<<i<<j;
	swap(i,j);
	cout<<i<<j<<endl;
	
	max(i,j)=4;
	cout<<i<<j<<endl;
	
	*min(&ri,&rj)=7;		//基本无二 
	cout<<i<<j<<endl;
	return 0;
} 

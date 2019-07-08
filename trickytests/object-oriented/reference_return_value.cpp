f#include <iostream>
using namespace std;

class Test{
public:
	Test(int a):num(a){}
	int get_num(){
		return num;
	}
	void set_num(int num){
		this->num = num;
	}
	int &get_num_change(){		//返回值带&的是可以[不安全]改变属性
		return num;
	}
private:
	int num;
};
int main(){
	Test a(5);
	cout<<a.get_num();
	a.set_num(6);
	cout<<a.get_num();
	a.get_num_change() = 7; //不推荐
	cout<<a.get_num();
}

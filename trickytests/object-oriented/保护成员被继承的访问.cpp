#include <iostream>
#include <cstring>
using namespace std;
class person{
public:
	person(char N[]="",char n[]="")
	{strcpy(Name,N);strcpy(Number,n);}
	~person(){}
protected:
	char Name[8];
	char Number[8];
};

class student:public person{
public:
	student(char N[], char n[],char cn[],double t):person(N,n)
	{strcpy(class_num,cn);Total = t;}
	
	~student(){}
	void display(){
		cout<<"姓名:"<<Name<<endl;
		cout<<"学号:"<<Number<<endl;
		cout<<"班级:"<<class_num<<endl;
		cout<<"总分:"<<Total<<endl;
	}
private:
	char class_num[8];
	double Total;
};
int main(void){
	student a("123","123","123",54.1);
	a.display();
} 

#include <iostream>
#include <cstring>
using namespace std;
class person{
public:
	person(char N[]="",char n[]="")
	{strcpy(Name,N);strcpy(Number,n);}
	~person(){}
	char *getName(){return this->Name;}
	char *getNumber(){return this->Number;}
private:
	char Name[8];
	char Number[8];
};

class student:public person{
public:
	student(char N[], char n[],char cn[],double t):person(N,n)
	{strcpy(class_num,cn);Total = t;}
	
	~student(){}
	void display(){
		cout<<"����:"<<getName()<<endl;
		cout<<"ѧ��:"<<getNumber()<<endl;
		cout<<"�༶:"<<class_num<<endl;
		cout<<"�ܷ�:"<<Total<<endl;
	}
private:
	char class_num[8];
	double Total;
};
int main(void){
	student a("123","123","123",54.1);
	a.display();
} 

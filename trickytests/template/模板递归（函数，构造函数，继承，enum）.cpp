#include <iostream>  
using namespace std;  
/****************类中静态成员****************/
template<int n>
struct fact0{
	enum {result = fact0<n - 1>::result * n};
	//也可以用static int result
};
template<>
struct fact0<1>{
	enum {result = 1};
};
/****************函数模板递归****************/
template<int n>
int fact1(){
	return n * fact1<n - 1>();
}
template<>
int fact1<1>(){
	return 1;
}
/****************构造函数模板递归****************/
template<int n>
struct fact2{
	fact2(int &result){
		result = result * n;
		fact2<n - 1>(result);
	}
};
template<>
struct fact2<1>{
	fact2(int &result){
		return ;
	}
};
/****************类模板继承自己递归****************/
template<int n>
struct fact3 : public fact3<n - 1>{
	fact3(int &result):fact3<n - 1>(result){
		result = result * n;
	}
};
template<>
struct fact3<1>{
	fact3(int &result){}
}; 
/*************运算符重载函数模板递归**************/
template<int n>
struct fact4{
	int operator()(){
		return n * fact4<n - 1>()();
	}
};
template<>
struct fact4<1>{
	int operator()(){
		return 1;
	}
};
/************************************************/
template<int n>
struct fact5 : public fact5<n - 1>{
	int operator()(){
		return n * fact5<n - 1>::operator()();
	}
};
template<>
struct fact5<1>{
	int operator()(){
		return 1;
	}
};
int main(){
	cout<<fact0<1>::result<<endl;
	cout<<fact1<2>()<<endl;
	int a = 1, b = 1;  
	#define function(f,a,b) {\
	}do{\
		f<a> lambda(b);\
	}while(0);
	function(fact2,3,a);
	function(fact3,4,b);
	cout<<a<<endl<<b<<endl;
	
	fact4<5> result;
	cout<<result()<<endl;
	cout<<fact4<5>()()<<endl;
	
	cout<<fact5<6>()()<<endl; 
    return 0; 
} 

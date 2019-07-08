#include <iostream>
using namespace std; 

template<int n>								//函数模板无法偏特化 
void hanoi(char a, char b, char c){
	hanoi<n - 1>(a, c, b);
	printf("%c -> %c\n", a, c);
	hanoi<n - 1>(b, a, c);
}
template<>
void hanoi<1>(char a, char b, char c){
	printf("%c -> %c\n", a, c);
}
////////////////////////////////////////////////
template<int n, char a, char b, char c>		//类模板可以偏特化 
class hanoi1{
public:
	static int hanoi(){
		hanoi1<n-1, a, c, b>::hanoi();
		printf("%c -> %c\n", a, c);
		hanoi1<n-1, b, a, c>::hanoi();
	}
};
template<char a, char b, char c>
class hanoi1<1, a, b ,c>{
public:
	static int hanoi(){
		printf("%c -> %c\n", a, c);
	}
};

int main(){ 
	constexpr int N = 4;
	cout<<"类模板偏特化：";
	hanoi1<N,'A','B','C'>::hanoi();
	cout<<endl;
	
	cout<<"函数模板全特化：";
	hanoi<N>('A','B','C'); 
	exit(0);
}

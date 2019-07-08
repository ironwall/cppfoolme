#include <iostream>
using namespace std;

template<int x>
struct fib1{
	static unsigned const result = fib1<x-1>::result + fib1<x-2>::result; 
};
template<>
struct fib1<2>{
	static unsigned const result = 1;
};
template<>
struct fib1<1>{
	static unsigned const result = 1;
};
template<int x>
struct fib2{
	enum{ 
		result = fib2<x-1>::result + fib2<x-2>::result
	};
};
template<>
struct fib2<2>{
	enum{
		result = 1
	}; 
};
template<>
struct fib2<1>{
	enum{
		result = 1
	};
};
template<int x>
struct fib3{
	static int result(){
		return fib3<x-1>::result()+fib3<x-2>::result();
	}
};
template<>
struct fib3<2>{
	static int result(){
		return 1;
	}
};
template<>
struct fib3<1>{
	static int result(){
		return 1;
	}
};
int main(){
	cout<<fib1<8>::result<<endl;
	cout<<fib2<8>::result<<endl;
	cout<<fib3<8>::result();
	return 0;
}

#include <iostream>  
#include <algorithm>  
  using namespace std;  

class func{
public:
    int c;

    class{
    public:
        void operator()(int a, int b) {
            func *pthis = ((func*)((char*)this - offsetof(func, add)));
            pthis->c = a + b;
        }
    }add;
};
/* func fu;
    fu.add(5, 6);
    cout << fu.c;
*/
//------------------------------------
struct add_prototype{
	int operator()(int x, int y) { return x + y; }
};

int fact(int x){
	struct{
		int operator()(int a){
			if(a==0)
				return 1;
			else
				return a*fact(a-1);		//同名函数而已 
		}
	}fact;
	return fact(x);
}
class fact2{
public:
	int operator()( int a){
		if(a==0)
			return 1;
		else
			return a*fact2()(a-1);	
	}
}fact2;

class{
	public:
		int operator()(int a){
			if(a == 0)
				return 1;
			else
				return a * this->operator()(a-1);
		}
}fact3;

class test{
	public:
		void setX(int x){
			struct shit{
				void operator()(test *p, int give){
					p->x=give;
				}
			}shit;
			shit(this,x);
		}
		int getX(){
			return x;
		}
	private:
		int x;
};
int main(){  
	int a=1, b=2;
	int c = add_prototype()(a,b);
	add_prototype functor;
	cout<<functor(a,b)<<" ";
	cout<<c<<endl;
	
	int x=1,y=2;
	cout<<fact(3)<<" ";
	cout<<fact2(6)<<endl;
	
	test tobj;
	tobj.setX(5);
	cout<<tobj.getX();
    return 0; 
} 

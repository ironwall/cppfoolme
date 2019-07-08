#include <iostream>
using std::cout;
using std::cin;

template <typename T>
class RemovePointer{
};

template <typename T>
class RemovePointer<T*>{
public:
    typedef T Result; //using Result = T;
};

int main(){
	typename RemovePointer<float*>::Result x = 5.0f;
	cout << x << std::endl;
}

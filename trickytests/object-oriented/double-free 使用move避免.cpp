#include <vector>
#include <utility>
#include <stdio.h>
#include <string.h>
 
using namespace std;
class demo
{
public:
    demo() :buffer(NULL)
    { 
        buffer = new char[200]; 
        strcpy(buffer, "hello world");
    }
    /*
	demo(const demo& src)
	{
    //buffer = new char[200];
		printf("copy assign function\r\n");
	}
    */
    demo(demo && obj){
      buffer = obj.buffer;
      obj.buffer = NULL;
    }
	~demo()
	{
		if (buffer != NULL)
			delete buffer;
		buffer = NULL;
	}
public:
    char *buffer;
};
 
void fun()
{
    demo a;
    vector<demo>  haha;
    haha.push_back(std::move(a));
}
 
int main(int argc, char* argv[])
{
    fun();
    printf("执行完毕\r\n");
    getchar();
    return 0;
}

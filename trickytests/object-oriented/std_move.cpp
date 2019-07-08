#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
    string s1("test"), s2;
    
    string &&s3 = std::move(s1);
    cout<<"s1"<<s1<<endl;
    cout<<"s2"<<s2<<endl;
    cout<<"s3"<<s3<<endl;
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
    
    s2 = move(s1);          //感觉身体被掏空……
    cout<<"s1"<<s1<<endl;
    cout<<"s2"<<s2<<endl;
    cout<<"s3"<<s3<<endl;
    return 0;
}

#ifndef TEST_TOOLS
#define TEST_TOOLS
#include <cxxabi.h>
#include <iostream>
using namespace std;
template<class T>
constexpr auto format_name(T a){
    return abi::__cxa_demangle(typeid(a).name(), 0, 0, 0);
}
template<class T>
constexpr void display(){
    T a;
    cout << abi::__cxa_demangle(typeid(a).name(), 0, 0, 0) << endl;
}
#define display(...) display<__VA_ARGS__>()
#endif
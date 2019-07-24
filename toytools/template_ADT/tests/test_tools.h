#ifndef TEST_TOOLS
#define TEST_TOOLS
#include <cxxabi.h>
using namespace std;
template<class T>
auto format_name(T a){
    return abi::__cxa_demangle(typeid(a).name(), 0, 0, 0);
}
#endif
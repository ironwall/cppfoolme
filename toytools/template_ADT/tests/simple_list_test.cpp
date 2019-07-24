#include <typeinfo>
#include <iostream>
#include <utility>
#include <cxxabi.h>
#include "../simple_List.h"
#include "./test_tools.h"
using std::cout;
using std::endl;

using namespace std;


int main(){
    cout << format_name(Car<List<Int<3>>>()) << endl;
    cout << format_name(
        append< List<Int<1>, Int<77>>, List<Int<1>,Int<2>>, List<Int<999>>>
        ()) << endl;
    cout << format_name(
        IntList<1, 2, 3, 4>
    ()) << endl;
    // make_list<1, 2, 3, 4> => List<Int<1>, Int<2>, Int<3>, Int<4>>;
    // cout << format(make_list<1,2,3,4>()) << endl;
}


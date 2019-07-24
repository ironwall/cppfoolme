#include <typeinfo>
#include <iostream>
#include "../list.h"
#include "./test_tools.h"
using namespace std;

int main(){
    //TEST list
    using test_list1 = list( i32(1) );
    cout << format_name(test_list1()) << endl;
    using test_list2 = list( i32(3), i32(2), i32(1) );
    cout << format_name(test_list2()) << endl;
    using test_list3 = list();
    cout << format_name(test_list3()) << endl;
    
    

    //TEST car
    using test_car1 = car(test_list1);
    cout << "test_car1: " << format_name(test_car1()) << endl;
    using test_car2 = car(test_list2);
    cout << "test_car2: " << format_name(test_car2()) << endl;

    //TEST cdr
    using test_cdr1 = cdr(test_list1);
    cout << "test_cdr1: " << format_name(test_cdr1()) << endl;
    using test_cdr2 = cdr(test_list2);
    cout << "test_cdr2: " << format_name(test_cdr2()) << endl;
}
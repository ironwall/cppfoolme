#include <typeinfo>
#include <iostream>
#include <utility>
#include "../cons_based_list.h"
#include "./test_tools.h"
using std::cout;
using std::endl;

int main(){
    //TEST list
    using test_list1 = list( i32(1) );
    cout << format_name(test_list1()) << endl;
    using test_list2 = list( i32(3), i32(2), list(i32(999)) );
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

    //TEST length
    using length1 = length(test_list1);
    cout << "test_length1 for '(1): \t\t" << format_name(length1()) << endl;
    using length2 = length(test_list2);
    cout << "test_length2 for '(3,2,1): \t" << format_name(length2()) << endl;
    using length3 = length(test_list3);
    cout << "test_length3 for '(): \t\t" << format_name(length3()) << endl;
}
#include "../simple_List.h"
#include "../base_types.h"
#include "../libs.h"
#include "./test_tools.h"

int main(){
    display(larger<Int(5), Int(1)>::value);
    using a = filter(larger<Int(9)>, IntList(9,0,5,8,9,4,3,1,2,6,7));
    using b = filter(smaller<Int(9)>, IntList(9,0,5,8,9,4,3,1,2,6,7));
    using c = filter(eq<Int(9)>, IntList(9,0,5,8,9,4,3,1,2,6,7,9));
    display(a);
     display(b);
    cout << "eq:  "; display(c);
    display(concat(b,c,a));
    using r = qksort<IntList(9,0,5,8,9,4,3,1,2,6,7,9)>::value;
    display(r);
    return 0;
}
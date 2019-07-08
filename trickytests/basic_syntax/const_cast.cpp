//
//  main.cpp
//  const_cast
//
//  Created by weicao on 9/28/18.
//  Copyright © 2018 weicao. All rights reserved.
//

#include <iostream>
class A{
public:
    A(int a){num = a;}
    int num;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    const int g = 222;
    int *gg = const_cast<int*>(&g);
    *gg = 111;
    std::cout << g << std::endl;             //没变
    //------------------------
    A* const test = new A(10);
    typedef A* AA;
    const AA test2 = new A(20);
    std::cout << test->num << std::endl;
    test->num = 11;
    std::cout << test->num << std::endl;
    //const_cast<A*>(test) = new A(12);     //没有卵用， test是常指针没法改
    //std::cout << test->num << std::endl;
    
    return 0;
}

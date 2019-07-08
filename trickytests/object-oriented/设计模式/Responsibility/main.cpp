//
//  main.cpp
//  Responsibility
//
//  Created by weicao on 10/4/18.
//  Copyright © 2018 weicao. All rights reserved.
//
#include "Responsibility.hpp"
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    abstractNode *test3 = new node10();
    abstractNode *test2 = new node5(test3);
    abstractNode *test1 = new node1(test2);


    test1->handleRequest(0);
    test1->handleRequest(3);
    test1->handleRequest(7);
    
    return 0;
}

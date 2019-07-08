//
//  Responsibility.hpp
//  Responsibility
//
//  Created by weicao on 10/4/18.
//  Copyright © 2018 weicao. All rights reserved.
//

#ifndef Responsibility_hpp
#define Responsibility_hpp

#include <iostream>
class abstractNode{             //actually it's a handler
public:
    abstractNode(){next = NULL;}
    abstractNode(abstractNode *successor){
        next = successor;
    }
    virtual ~abstractNode(){}
    void setSuccessor(abstractNode *successor){
        next = successor;
    }
    abstractNode* getSuccessor(){
        return next;
    }
    virtual void handleRequest(int number) = 0;
protected:
    abstractNode *next;
};

class node1:public abstractNode{
public:
    node1(){}
    node1(abstractNode *succ):abstractNode(succ){};
    virtual void handleRequest(int number) override{
        if(number <= 1){
            std::cout << "Power of node(1)'s obj: " << number << std::endl;
        }else{
            getSuccessor() -> handleRequest(number);
        }
    }
};
class node5:public abstractNode{
public:
    node5(){}
    node5(abstractNode *succ):abstractNode(succ){}
    virtual void handleRequest(int number) override{
        if(number <= 5){
            std::cout << "Power of node(5)'s obj: " << number << std::endl;
        }
        else{
            this -> getSuccessor() -> handleRequest(number);
        }
    }
};
class node10:public abstractNode{
public:
    node10(){}
    node10(abstractNode *succ):abstractNode(succ){}
    virtual void handleRequest(int number) override{
        if(number <= 10){
            std::cout << "Power of node(10)'s obj: " << number << std::endl;
        }
        else{
            this -> getSuccessor() -> handleRequest(number);
        }
    }
};
#endif /* Responsibility_hpp */

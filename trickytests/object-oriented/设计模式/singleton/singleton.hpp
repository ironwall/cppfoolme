//
//  singleton.hpp
//  singleton
//
//  Created by weicao on 9/28/18.
//  Copyright © 2018 weicao. All rights reserved.
//

#ifndef singleton_hpp
#define singleton_hpp

#include <stdio.h>

class singleton{
public:
    static singleton* getInstance();
    static void release();
private:
    singleton(){}
    ~singleton(){}
    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;
    
    static singleton* instance;
    
    class GC{
    public:
        ~GC(){
            release();
        }
    };
    
    static GC gc;
};
singleton* singleton::instance = new singleton;
singleton::GC singleton::gc;
singleton* singleton::getInstance(){
    return instance;
}
void singleton::release(){
    if(instance == nullptr){
        delete instance;
        instance = nullptr;
    }
}

#endif /* singleton_hpp */

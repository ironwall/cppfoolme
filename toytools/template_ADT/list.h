#ifndef TLIST_H
#define TLIST_H
#include "macro_tools.h"
//---------------------Basic data types----------------------
template<int N>
struct i32{
    enum{value = N};
};
#define i32(n) i32<n>
//-----------------------------------------------------------

//---------------------cons and list-------------------------
struct nil{};

template<class DATA, class LIST>
struct cons{};
template<class DATA>
struct cons<DATA, nil>{};
#define cons(...) cons<__VA_ARGS__>

template<class HEAD, class ...TAIL>
struct __list__{
    using value = cons< HEAD, typename __list__<TAIL...>::value >;
};
template<class HEAD>
struct __list__<HEAD>{
    using value = cons<HEAD, nil>;
};
template<class ...ITEMS>
using list = typename __list__<ITEMS...>::value;

#define list(...) \
IF_ELSE(IS_NOT_EMPTY(GET_FIR(__VA_ARGS__)))( \
    nil \
)( \
    list<__VA_ARGS__> \
) 
//-----------------------------------------------------------

//---------------------functions for list--------------------
template<class LIST>
struct __car__{};
template<class HEAD, class LIST>
struct __car__<cons<HEAD, LIST>>{
    using value = HEAD;
};
template<class LIST>
using car = typename __car__<LIST>::value;
#define car(x) car<x>

template<class LIST>
struct __cdr__{};
template<class HEAD, class LIST>
struct __cdr__<cons<HEAD, LIST>>{
    using value = LIST;
};
template<class LIST>
using cdr = typename __cdr__<LIST>::value;
#define cdr(x) cdr<x>
//-----------------------------------------------------------

#endif
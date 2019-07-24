#ifndef USECONS
#define USECONS
#include "macro_tools.h"
#include "base_types.h"

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
template<int a, int...nums>
struct __intlist__{
    using value = cons<i32<a>, typename __intlist__<nums...>::value>;
};
template<int a>
struct __intlist__<a>{
    using value = cons<i32<a>, nil>;
};
template<int...nums>
using intlist = typename __intlist__<nums...>::value;
#define intlist(...) intlist<__VA_ARGS__>
//-----------------------------------------------------------

//---------------------functions for list--------------------
//----------car------------
template<class LIST>
struct __car__{};
template<class HEAD, class LIST>
struct __car__<cons<HEAD, LIST>>{
    using value = HEAD;
};
template<class LIST>
using car = typename __car__<LIST>::value;
#define car(x) car<x>
//----------car-------------

//----------cdr-------------
template<class LIST>
struct __cdr__{};
template<class HEAD, class LIST>
struct __cdr__<cons<HEAD, LIST>>{
    using value = LIST;
};
template<class LIST>
using cdr = typename __cdr__<LIST>::value;
#define cdr(x) cdr<x>
//----------cdr-------------

//----------length----------
template<class LIST>
struct __length__{};
template<class HEAD, class LIST>
struct __length__<cons<HEAD, LIST>>{
    using value = i32<1 + __length__<LIST>::value::value >;
};
template<class HEAD>
struct __length__<cons<HEAD, nil>>{
    using value = i32<1>;
};
template<>
struct __length__<nil>{
    using value = i32<0>;
};
template<class LIST>
using length = typename __length__<LIST>::value;
#define length(x) length<x>
//----------length----------


//-----------------------------------------------------------

#endif
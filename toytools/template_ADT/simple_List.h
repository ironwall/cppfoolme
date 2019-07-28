#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H
#include "base_types.h"
#include "macro_tools.h"
#include "libs.h"

template<class...items>
struct List{};
#define List(...) List<__VA_ARGS__>

template<class...args>
struct car{};
// template<class list>
// struct car{};
template<class head, class...yail>
struct car<List<head, yail...>>{
    using value = head;
};
#define car(...) car<__VA_ARGS__>::value
#define head(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    car<> \
)( \
    car<__VA_ARGS__>::value \
) 

template<class...args>
struct cdr{};
// template<class list>
// struct cdr{};
template<class head, class...tail>
struct cdr<List<head, tail...>>{
    using value = List<tail...>;
};
/*
    template<>
    struct cdr<List<>>{
        using value = List<>;
    };
 */
#define cdr(...) cdr<__VA_ARGS__>::value
#define tail(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    cdr<> \
)( \
    cdr<__VA_ARGS__>::value \
) 

template<class ...args>
struct concat{};
// template<class list1, class list2>
// struct concat{};
template<class list, class...rest>
struct concat<list, rest...>{
    template<class...args>
    struct make_concat2{};
    template<class...T1, class...T2>
    struct make_concat2<List<T1...>, List<T2...>>{
        using value = List<T1..., T2...>;
    };
    template<class List1, class List2>
    using concat2 = typename make_concat2<List1, List2>::value;

    using value = concat2<list, typename concat<rest...>::value>;
};
template<class onlyone>
struct concat<onlyone>{
    using value = onlyone;
};
//#define concat(a, ...) concat<a, __VA_ARGS__>::value
#define concat(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    concat<> \
)( \
    concat<__VA_ARGS__>::value \
) 

template<class...args>
struct append1{};
// template<class A, class B>
// struct append1{};
template<class B, class...items>
struct append1<List<items...>, B>{
    using value = List<items...,B>;
};
template<class B, class...items>
struct append1<B, List<items...>>{
    using value = List<items...,B>;
};
#define append1(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    append1<> \
)( \
    append1<__VA_ARGS__>::value \
) 

template<class...args>
struct prepend1{};
// template<class A, class B>
// struct prepend1{};
template<class B, class...items>
struct prepend1<List<items...>, B>{
    using value = List<B, items...>;
};
template<class B, class...items>
struct prepend1<B, List<items...>>{
    using value = List<B, items...>;
};
#define prepend1(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    prepend1<> \
)( \
    prepend1<__VA_ARGS__>::value \
) 

template<int a, int...nums>
struct IntList{
    using value = typename 
        concat< 
            List<Int<a>>,
            typename IntList<nums...>::value
        >::value;
};
template<int a>
struct IntList<a>{
    using value = List<Int<a>>;
};
#define IntList(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    List<> \
)( \
    IntList<__VA_ARGS__>::value \
) 

template<class...args>
struct filter{};
template<template<class...> class Fn, class...args, class x, class...rest>
struct filter<Fn<args...>, List<x, rest...>>{
    using value = typename ifelse< typename Fn<x,args...> ::value, 
        typename prepend1<x, typename filter<Fn<args...>, List<rest...>> ::value> ::value , 
        typename filter<Fn<args...>, List<rest...>>::value > ::value;
};
template<class Fn>
struct filter<Fn, List<>>{
    using value = List<>;
};
template<class Fn>
struct filter<Fn>{
    using value = List<>;
};
#define filter(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    filter<> \
)( \
    filter<__VA_ARGS__>::value \
) 

template<class...args>
struct qksort{};
template<class x, class...rest>
struct qksort<List<x, rest...>>{
    using value = 
        typename concat<
            typename qksort< typename filter<smaller<x>, List<rest...>>::value>::value,
            List<x>,typename qksort< typename filter<eq<x>, List<rest...>>::value>::value,
            typename qksort< typename filter<larger<x>, List<rest...>>::value>::value
        >::value;
};
template<>
struct qksort<List<>>{
    using value = List<>;
};
#define qksort(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    filter<> \
)( \
    qksort<__VA_ARGS__>::value \
) 

//filter<larger<3>, IntList(1,2,3)>
//template<class >
//-------------------------------------------------------------------------
template<class T>
struct eval_fn1_pa1{
    using value = T;
};
template<template<class> class Fn, class P>
struct eval_fn1_pa1<Fn<P>>{
    using value = typename Fn< typename eval_fn1_pa1<P>::value > ::value;
};

template<class T>
struct eval_fn1{
    using value = T;   
};
#endif
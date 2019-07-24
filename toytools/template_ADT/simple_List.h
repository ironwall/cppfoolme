#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H
#include "base_types.h"

template<class...items>
struct List{};

template<class List>
struct make_Car{};
template<class Head, class...Tail>
struct make_Car<List<Head, Tail...>>{
    using value = Head;
};
template<class List>
using Car = typename make_Car<List>::value;
template<class List>

struct make_Cdr{};
template<class Head, class...Tail>
struct make_Cdr<List<Head, Tail...>>{
    using value = List<Tail...>;
};
template<class List>
using Cdr = typename make_Cdr<List>::value;

template<class List, class...Args>
struct make_append{
    template<class List1, class List2>
    struct make_append2{};
    template<class...T1, class...T2>
    struct make_append2<::List<T1...>, ::List<T2...>>{
        using value = ::List<T1..., T2...>;
    };
    template<class List1, class List2>
    using append2 = typename make_append2<List1, List2>::value;

    using value = append2<List, typename make_append<Args...>::value>;
};
template<class List>
struct make_append<List>{
    using value = List;
};
template<class List, class...Args>
using append = typename make_append<List, Args...>::value;

template<int a, int...nums>
struct make_IntList{
    using value = append<List<Int<a>>, typename make_IntList<nums...>::value>;
};
template<int a>
struct make_IntList<a>{
    using value = List<Int<a>>;
};
template<int...nums>
using IntList = typename make_IntList<nums...>::value;
#endif
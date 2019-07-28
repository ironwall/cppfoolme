#ifndef LIBS_H
#define LIBS_H
#include "./base_types.h"

template<class cond, class t, class f>
struct ifelse{};
template<class t, class f>
struct ifelse<Bool<true>, t, f>{
    using value = t;
};
template<class t, class f>
struct ifelse<Bool<false>, t, f>{
    using value = f;
};

template< /* class Fn, */ class...Args>
struct apply{};
template< template<class...> class Fn, class...Exist, class...Args>
struct apply<Fn<Exist...>, Args...>{
    using value = typename Fn<Exist..., Args...>::value;
};

#define apply(...) apply<__VA_ARGS__>::value

template<class...args>
struct larger{};
// template<class T, class V>
// struct larger{};
template<int a, int b>
struct larger<Int<a>, Int<b>>{
    using value = typename ifelse< Bool<bool(a>b)>, Bool<true>, Bool<false>>::value;
};

template<class...args>
struct smaller{};
// template<class T, class V>
// struct smaller{};
template<int a, int b>
struct smaller<Int<a>, Int<b>>{
    using value = typename ifelse< Bool<bool(a<b)>, Bool<true>, Bool<false>>::value;
};

template<class...args>
struct eq{};
template<class T>
struct eq<T,T>{
    using value = Bool<true>;
};
template<class T, class V>
struct eq<T,V>{
    using value = Bool<false>;
};

#endif
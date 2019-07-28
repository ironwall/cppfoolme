#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H
struct Nil;

template<int N>
struct Int{};
#define Int(x) Int<x>

template<char N>
struct Char{};
#define Char(x) Char<x>

template<int a, int b>
struct Float{};
#define Float(a, b) Float<a, b>

template<bool b>
struct Bool{};
#define Bool(x) Char<x>

template<class...Args>
struct add2{};
template<class num1, class num2>
struct add2<num1, num2>{};
template<int a, int b>
struct add2<Int<a>, Int<b>>{
    using value = Int<a + b>;
};
template<int a_1, int a_2, int b_1, int b_2>
struct add2<Float<a_1, a_2>, Float<b_1, b_2>>{
    using value = Float<a_1 + b_1, a_2 + b_2>;
};
template<int a_1, int a_2, int b>
struct add2<Float<a_1, a_2>, Int<b>>{
    using value = Float<a_1 + b, a_2>;
};
template<int a_1, int a_2, int b>
struct add2<Int<b>, Float<a_1, a_2>>{
    using value = Float<a_1 + b, a_2>;
};

template<class...Args>
struct add{};
template<class numA, class numB, class...Args>
struct add<numA, numB, Args...>{
    using value = typename add2 < 
                    numA,
                    typename add<numB, Args...>::value
                  > ::value;
};
template<class numA, class numB>
struct add<numA, numB>{
    using value = typename add2< numA, numB > ::value;
};
#define add(...) \
IF_ELSE(I$_EMPTY(GET_FIR(__VA_ARGS__)))( \
    add<> \
)( \
    add<__VA_ARGS__>::value \
) 


#endif
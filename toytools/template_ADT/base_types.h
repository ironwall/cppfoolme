#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H
template<int N>
struct i32{
    enum{value = N};
};
#define i32(n) i32<n>
template<char N>
struct chr{
    enum{value = N};
};
#define chr(n) chr<n>

template<int N>
using Int = i32<N>;
#endif
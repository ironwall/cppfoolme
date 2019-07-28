
#ifndef MACRO_TOOLS
#define MACRO_TOOLS

//------------------------------------------------------------------
/*
    Author:
    冯昱尧

    Reference link:
    https://zhuanlan.zhihu.com/p/27146532
    https://zhuanlan.zhihu.com/p/27024686
    
 */
#define PRIMITIVE_CAT(x, y) x ## y
#define CAT(x, y) PRIMITIVE_CAT(x, y)
#define GET_SEC(x, n, ...) n
#define GET_FIR(x, ...) x
#define CHECK(...) GET_SEC(__VA_ARGS__, 0)
#define PROBE(x) x, 1

#define COMPL(b) PRIMITIVE_CAT(COMPL_, b)
#define COMPL_0 1
#define COMPL_1 0

#define IS_EMPTY(x) CHECK(CAT(PRIMITIVE_CAT(IS_EMPTY_, x), 0))
#define IS_EMPTY_0 PROBE()

#define IS_PAREN(x) CHECK(IS_PAREN_PROBE x)
#define IS_PAREN_PROBE(...) PROBE()

#define NOT(x) CHECK(PRIMITIVE_CAT(NOT_, x))
#define NOT_0 PROBE()

#define BOOL(x) COMPL(NOT(x))
#define IF(c) IIF(BOOL(c))

#define IF_ELSE(condition) CAT(_IF_,  BOOL(condition))
#define _IF_1(...) __VA_ARGS__ _IF_1_ELSE
#define _IF_0(...)             _IF_0_ELSE

#define _IF_1_ELSE(...)
#define _IF_0_ELSE(...) __VA_ARGS__
        /*
        Usage:
        IF_ELSE (0) (      \
            True branch    \
        )(                 \
            False branch   \
        )
        -> CAT(_IF_, 0) (True branch) (False branch)
        -> _IF_0 (True branch) (False branch)
        -> _IF_0_ELSE (False branch)
        -> False branch

        IF_ELSE (1) (      \
            True branch    \
        )(                 \
            False branch   \
        )
        -> CAT(_IF_, 1) (True branch) (False branch)
        -> _IF_1 (True branch) (False branch)
        -> True branch _IF_1_ELSE_ (False branch)
        -> True branch
        */
//-----------------------------------------------------------------------------

#define I$_EMPTY(x) CHECK(PRIMITIVE_CAT(I$_EMPTY_0, x))
#define I$_EMPTY_0 PROBE()

#endif
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "sim3.h"
//f(x,y)
/*
Exact simulation sequence 4 * 4 = 16, every symbol 2 bits, 16 * 2 = 32 bits, a 32 bit unsigned number could handle the situation
y x  RAnd ROr
0 0  0    0
0 X  0    X
0 ~X 0    ~X
0 1  0    1

X 0  0    X
X X  X    X
X ~X 0    1
X 1  X    1

~X 0 0    ~X
~X X 0    1
~X ~X ~X  ~X
~X 1 ~X   1

1 0  0    1
1 X  X    1
1 ~X ~X   1
1 1  1    1
*/
int Sim3On2()
{
    int32_t x = maskTT[0];
    int32_t y = maskTT[1];

    /*
    AND Expected result
    1~XX0 ~X~X00 X0X0 0000
     = 11100100 10100000 01000100 00000000
     = 0xE4A04400
    */
    int32_t resAnd = x & y;
    int32_t compResAnd = 0xE4A04400;
    assert(resAnd == compResAnd);
    printf("Successfully exact simulated AND f(x,y) on 3 values.\n");

    /*
    OR Expected result
    1111 1~X1~X 11XX 1~XX0
     = 11111111 11101110 11110101 11100100
     = 0xFFEEF5E4
    Verify OR by using D-Morgan's law and transform to AND and INV operation
    */
    int32_t resOr = ~(~x & ~y);
    int32_t compResOr = 0xFFEEF5E4;
    assert(resOr == compResOr);
    printf("Successfully exact simulated OR f(x,y) on 3 values.\n");

    return 0;
}

int main()
{
    Sim3On2();
    return 0;
}

/*
Define 3 value 0,1,X in bit level, for simulation.
@Author: Jingren Wang
@Date: 10/06/2025

This is a simple demo for encoded 3 value simulation.
*/

/*
0 -> [0,0]
X -> [0,1]

Generally sort by the order of 0 < X < ~X < 1.

Define basic rules:
1. 1(~0) -> [1,1]
2. ~X -> [1,0]
3. 0 & * -> 0
4. 0 | * -> *
5. 1 & * -> *
6. 1 | * -> 1
7. X & X -> X
8. X | X -> X
9. X & ~X -> 0
10. X | ~X -> 1
*/
#include <stdint.h>
typedef unsigned int eleVar;
/*
Simulation magic number
1 ~X X 0
--------
1 var
11100100
--------
2 vars
11100100 11100100 11100100 11100100 (0xE4E4E4E4)
11111111 10101010 01010101 00000000 (0xFFAA5500)
*/
static eleVar maskTT[] = 
{
    0xE4E4E4E4,
    0xFFAA5500
};

//TODO: @Jingren Wang Extend to arbitrary number of variables

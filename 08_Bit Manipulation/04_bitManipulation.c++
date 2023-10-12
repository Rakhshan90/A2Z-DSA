/*
1 is called set bit in binary number system
*/

/*
Problem statement: You have a 32-bit unsigned integer called 'num'and another integer called 'i'. You need to perform the following operations on the 'num' integer based on the value of 'i':
1. Get the bit value at the "i"th position of "num'.
2. Set the bit at the "i"th position of "num".
3. Clear the bit at the "i"th position of "num".
We are starting bits from 1 instead of O. (1-based)
*/

/*
Approach: 
1. For first operation, we will shift num to the right by i-1 times, so that ith bit moved to the right most position, then we will & with 1 to get the ith bit as a LSB.
2. For second operation, we will take 1 at position 1 and left shfit 1 by i-1 times, so that 1 will move to the ith position of num, then we will | with num.
3. For third operation, We have already set 1 at ith position of num in op2. we also know that xor of 1^1 results 0. so we will again take one at position 1 and left shfit 1 by i-1 times, so that 1 will move to the ith position of num, then we will ^ with op2.

TC:O(1), SC:O(1)
*/

/*
vector<int> bitManipulation(int num, int i){
    int op1 = num>>(i-1) & 1;
    int op2 = 1<<(i-1) | num;
    int op3 = 1<<(i-1) ^ op2;

    return {op1, op2, op3};
}
*/
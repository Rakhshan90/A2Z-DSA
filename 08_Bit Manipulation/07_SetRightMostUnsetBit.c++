/*
The problem is to find the rightmost bit of a non-negative number 'N'that is currently unset (i.e., has a value of O) in its binary representation and set it to 1. Return the number after setting the rightmost unset bit of 'N'. If there are no unset bits in N's binary representation, then the number should remain unchanged.
*/

/*
Approach:
1. First find the index of the rightmost 0 bit in the integer N. This is done using the function findIndex(). 
2. Once the index of the rightmost 0 bit is known, then sets the rightmost bit to 1 by using the bitwise OR operator (|).


TC:O(log N), SC:O(1)
*/
/*
int findIndex(int N){
    int i = 1;
    while(N != 0){
        int LSB = N & 1;
        if(LSB == 0){
            return i;
            break;
        }
        i++;
        N = N >> 1;
    }
    return 1;
}
int setBits(int N){
    int index = findIndex(N);
    return (1 << (index - 1) | N);
}
*/
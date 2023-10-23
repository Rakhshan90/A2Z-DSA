/*
Problem statement: A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.
*/

/*
Approach : Bit manipulation
1. Find XOR of start and goal and store in a variable i.e, xr.
2. We have to just count the Set Bits(1) in result of xr.
3. Total number set bits(1) will be our answer, which represents total number of flips required in start to get goal.

TC: O(log n), SC : O(1)
*/
/*
int minBitFlips(int start, int goal) {
        int cnt = 0;
        int xr = start ^ goal;
        while(xr != 0){
            int LSB = xr & 1;
            if(LSB == 1) cnt++;
            xr = xr >> 1;
        }
        return cnt;
    }
*/
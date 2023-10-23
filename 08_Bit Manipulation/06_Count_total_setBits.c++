/*
Problem statement: For a given integer 'N', you have to return the number of set bits in
the binary representation of the numbers from 1 to N'.
In a binary number '1' is considered as a set bit and '0' as not set.
*/

/*
Approach 1: Navie approach
We know how count set bits for any number. So we use same approach for 1 to N to count total set bits.

TC: O(N * log N) , log N for counting set bits for a number. N * log N for all numbers 1 to N.
SC: O(1)
*/

/*
int findSetBits(int i){
    int setBits = 0;
    while(i != 0){
        int LSB = i & 1;
        if(LSB == 1) setBits++;
        i = i >> 1;
    }
    return setBits;
}
int countSetBits(int N)
{
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        cnt += findSetBits(i);
    }
    return cnt;
}
*/


/*
Approach 2: Optimal approach
Intuition: The code works by recursively dividing the number N into smaller portions and counting the number of set bits in each portion. The base case is when N is equal to 0, in which case the number of set bits is 0.

1. We are dividing our problem or we can say range N into three portions.
2. The first portion is equal to the largest power of 2 within the range N. This protion gives total bits equal to pow(2, x-1) * x.
3. The second portion is equal to N minus the largest power of 2 that is less than or equal to N plus 1. This portion gives total bits equal to N - pow(2, x) + 1.
4. The third portion is equal to N minus the largest power of 2 that is less than or equal to N.
This portion gives total bits equal to N - pow(2, x). This portion is the sub problem so we can use recursion to solve this sub problem.

TC: O(log n), bcoz problem recursively divides into sub problems or portions.
SC: O(log n), due to recursive stack that stores recursive calls.
*/

/*
int largestPowerOfTwo(int N){
    int x = 0;
    while((1 << x) <= N){
        x++;
    }
    return x-1;
}
int countSetBits(int N)
{
    if(N == 0) return 0;
    
    int x = largestPowerOfTwo(N);
    int portion1 = x * (1 << (x-1));
    int portion2 = N - (1 << (x)) + 1;
    int portion3 = N - (1 << (x));
    int ans = portion1 + portion2 + countSetBits(portion3);
    return ans;
}
*/
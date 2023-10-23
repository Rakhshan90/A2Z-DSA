/*
Problem statement: You are given two numbers 'L'and 'R'. Find the XOR of the elements in the range [L, R].
*/


/*
Approach 1: Brute-force approach
We can simply run loop form L to R and we will find xor of each element. At the end, we will have final result. 
TC: O(N), SC: O(1)
*/

/*
Approach 2: Bit manipulation
1. We know how to find xor of all elements from 1 to N in O(1) time.
2. We will find xor of the elements in the range [1, L-1], and we will find xor of the elements in the range [1, R] by using optimized approach that takes O(1) time.
3. Then, we will xor of both the results, such as xor(R) ^ xor(L-1). This final result will be our answer.

TC: O(1), SC: O(1)
*/

/*
int xr(int n){
    if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n+1;
    else if(n % 4 == 3) return 0;
    else return n;    //n % 4 == 0 
}
int findXOR(int L, int R){
    return xr(R) ^ xr(L-1);
}
*/
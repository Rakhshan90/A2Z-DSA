/*
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
*/

/*
Intuition : We know that for even positions there will be 5 possiblities and for odd positions there will be 4 possiblities. We need to calculate total number of goods numbers. Therefore we can simplye multiply total odd positions with 4 and total even positions with 5. finally the answer will be muliplication of all good numbers at odd positions and all goog numbers at even positions.
Appraoch 1: 
We can simply iterate over the given length n. For all even index we mulitply wiht 5 and for all odd index we multiply with 4. Finally, our answer will be muliplication of all evens and odds  

Note : This will not work when n will be more larger
*/

/*
Intuition : We know that for even positions there will be 5 possiblities and for odd positions there will be 4 possiblities.
Appraoch 2: By using recursion and logic of myPow recursion fuction
1. We will find total number of odd positions and even positions in given length n
2. We will calculate 5 raised to the power even positions and 4 raised to the power odd positions
3. We will mulitply both 5^evens and 4^odds and return our answer.
4. Keep in mind that we have to mod the answer at every step because question said answer can be large it can overflow. 

TC: O(log n), SC: O(log n)
*/

/*
//defining macro
#define mod 1000000007;
class Solution {
public:
    long long myPow(long long x, long long y){
        if(y==0) return 1;
        long long ans = myPow(x, y/2);
        ans *= ans; //ans = ans * ans
        ans%=mod; //ans = ans % mod;
        if(y%2==1) ans*=x; //ans = ans*x;
        ans%=mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
        return (myPow(5, even) * myPow(4, odd)) % mod; 
    }
};
*/
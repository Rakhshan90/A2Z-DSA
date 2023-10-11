/*
You are given two integers 'n', and 'm'. Calculate 'gcd(n,m)', without using library functions.
The greatest common divisor (gcd) of two numbers 'n' and 'm' is the largest positive number that divides both 'n' and 'm' without leaving a remainder.

Input: n = 6, m = 4
Output : 2
*/

/*
Approach 1: Naive (Brute-Force)
Intuition: Simply traverse from 1 to min(a,b) and check for every number.

Approach: 
Traverse from 1 to min(a,b).
And check if i is divisible by both a and b.If yes store it in the answer.
Find the maximum value of i which divides both a and b.

or may be we can traverse from right to left as we want to greatest common divisor. But, still there will be some case when we need to entire min number form left to right, so still 
TC: O(min(n, m)), SC:O(1)
*/
/*
#include<bits/stdc++.h>
int calcGCD(int n, int m){
    int gcd = 1;
    for(int i=min(n, m); i>=0; i--){
        if(n % i == 0 && m % i == 0){
            gcd = i;
            break;
        }
    }    
    return gcd;
}
*/

/*
Arpproach 2: Using Euclidean's theorem (Optimal approach)
gcd(n, m) = gdc(n % m, m) if(n>m). repeat this process until one among n, m becomes zero and other non-zero will be our gcd.

TC:O(log n), SC:O(1)
*/
/*
int calcGCD(int n, int m){
    while(n!=0 && m!=0){
        if(n > m) n = n % m;
        else m = m % n;
    }
    if(n == 0) return m;
    else return n;
}
*/
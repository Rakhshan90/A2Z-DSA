/*
Problem statement: Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
*/

/*
Approach 1: Naive approach (Exteme Brute-Force)
We know that range of an inter is -2^31 to 2^31 -1. So, we will loop from 0 to 30 and calculate all possible powers of 2 and compare it with n. if any pow(2, i) is equal to n, we can say that n is the power of 2.
*/
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0; i<=30; i++){
            int ans = pow(2, i);
            if(ans == n)
                return true;
        }
        return false;
    }
};
*/


/*
Approach 2: Better
Intution: By observation, we can say that all the numbers of power 2 have only 1 bit necessary. We can count all set(1) bits of given n, if count is 1, we will definitely sure that the n is power of 2. otherwise, n is something else. 

1. we know for sure that any power of 2 will always be positive number. we will return false if n <= 0.
2. While n is not equal to 0, find LSB.
3. if LSB is 1, increment the count.
4. shift n by 1 bit to the right to precess further LSB bits.
5. when loop exits, check if count is 1 return true, otherwise return false.
*/


/*
bool isPowerOfTwo(int n)
{	
    //edge case
    if(n <= 0) return false;
    
    int cnt = 0;
    while(n!=0){
        int LSB = n & 1;
        if(LSB == 1) cnt++;
        n = n >> 1; 
    }
    if(cnt == 1) return true;
    else return false;
}
*/


/*
Approach 3: Optimal
Intution: Now we know, that all the numbers of power 2 have only 1 bit necessary.
If we observe clearly, By performing bitwise & to both n and n-1 will return 0 if n is power of 2.
otherwise, n is something else. 

TC: O(1), SC:O(1)
*/

/*
bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    else return ((n & n-1)) == 0;
}
*/
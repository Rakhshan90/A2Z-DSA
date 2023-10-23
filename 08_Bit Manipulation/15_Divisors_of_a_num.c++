/*
Problem statement: Given an integer 'N', return all the divisors of 'N' in ascending
order.
*/

/*
Solution 1: Brute-force 
1. This is the basic approach. As we know the possible candidates, we iterate upon all the candidates and check whether they divide the actual number.
2. If it divides, then it is one of the divisors. Therfore, we print it.
3. If it does not divide, then it is not a divisor. We do this for all the candidates.

TC: O(n), SC: O(1)
*/

/*
vector<int> printDivisors(int n) {
    vector<int>ans;
    for(int i=1; i<=n; i++){
        if(n%i==0) ans.push_back(i);
    }
    return ans;
}
*/

/*
Solution 2: Optimized 
Intuition: 
1. If we take a closer look, we can notice that the quotient of a division by one of the divisors is actually another divisor. Like, 4 divides 36. The quotient is 9, and 9 also divides 36.
2. Another intuition is that the root of a number actually acts as a splitting part of all the divisors of a number.
3. Also, the quotient of a division by any divisor gives an equivalent divisor on the other side. Like, 4 gives 9 while dividing 36.

Approach: 
1. Initialize a vector to store the divisors of n.
2. Iterate over all the numbers from 1 to the square root of n.
3. If a number divides n, then add the number to the list of divisors.
4. If the quotient of n and the number is not equal to the number itself, then add the quotient to the list of divisors.
5. Sort the list of divisors in ascending order.
6. Return the list of divisors. 


TC: O(sqrt(n)) + O(num of divisors * log(num of divisors)) ~ TC: O(sqrt(n))
SC: O(1)
*/

/*
vector<int> printDivisors(int n) {
    vector<int>ans;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0) {
            ans.push_back(i);
            //quotient is also divisor, but make sure quotient should not same as divisor 
            if(n / i != i) ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
*/
/*
Problem statement: You are given an integer 'N'.
You must return the unique prime factors of 'N' in increasing order.
*/

/*
Approach 1: Brute-force approach
This approach works by iterating over all the numbers from 2 to n and checking if each number divides n. If a number divides n, then the number is added to the list of prime factors. The code then divides n by the number and continues iterating. The process terminates when n is equal to 1.

TC: outer loop iterates over all the numbers from 2 to the square root of n. 
    inner loop iterates at most log n. 
    overall TC: O(sqrt(n) log n).
SC: O(sqrt(n))
*/

/*
vector<int> countPrimes(int n)
{
    vector<int>ans;
    for(int i = 2; i <= n; i++){
        if(n % i == 0) ans.push_back(i);
        while(n != 1 && n % i == 0){
            n = n / i;
        }
        if(n == 1) break;
    }
    return ans;
}
*/

/*
Approach 2: Using Sieve of Eratosthenes
In previous approach, we are checking if each number divides n, but here we are checking if all prime numbers divides n, then the prime number is added to the list of prime factors. The code then divides n by the prime number and continues iterating. The process terminates when n is equal to 1.

TC: O(sqrt(n))
SC: O(n)
*/

/*
vector<int> countPrimes(int n)
{
    vector<int>ans;
    //Find all the prime numbers of within limit n
    vector<int> prime(n+1, 0);
    for(int i=2; i*i<=n; i++){
        if(prime[i] == 0){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 1;
            }
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(prime[i] == 0 && n % i == 0){
            ans.push_back(i);
            while(n != 1 && n % i == 0){
                n = n / i;
            }
        }
        if(n == 1) break;
    }

    return ans;
}
*/
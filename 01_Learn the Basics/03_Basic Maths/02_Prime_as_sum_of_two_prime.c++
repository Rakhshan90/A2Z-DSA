/*
Problem statement: Check if a prime number can be expressed as sum of two Prime Numbers
*/

/*
#################################  Solution ########################################

Intuition: 
-> We know that prime numbers are always Odd. So a prime number (odd) cannot be written as the sum of 2 odd prime numbers. So either of them has to be 2. 
-> Now our question boils down to checking whether n-2 && n prime or not. If both hold true return Yes or No

Approach:
->  We will create 2 functions : 
To check Prime number 
To check whether both N and N-2 are prime or not
-> In checking the Prime Function, we will run a loop from i =2  to sqrt(n). If n % i is equal to 0, that means i  is divisible by n, so it's not a prime number we will return false.
-> Same above can be done for n-2.

TC: O(sqrt(n)), SC: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void canWeExpress(int n)
{
    if (isPrime(n) && isPrime(n - 2)) cout<<"Given prime number "<<n<<" can be expressed as sum of two Prime Numbers";
    else cout<<"Given prime number "<<n<<" can't be expressed as sum of two Prime Numbers";
}
int main()
{
    int n;
    cin >> n;
    canWeExpress(n);
    return 0;
}
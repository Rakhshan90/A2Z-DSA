/*
The Sieve of Eratosthenes is a simple and efficient algorithm for finding all prime numbers up to a given limit. The algorithm works by creating a list of all numbers from 2 to the given limit and then marking all multiples of each prime number as non-prime. The algorithm terminates when all the numbers in the list that are not marked are prime.

TC: O((N*log*log N)) This is because the algorithm needs to iterate over all the numbers from 2 to the given limit and mark all multiples of each prime number as non-prime. The number of times the algorithm needs to iterate over a number is proportional to the logarithm of the number.

SC: O(N)
*/
#include<bits/stdc++.h>

using namespace std;

int sieveEratosthenes(int n){
    vector<int> prime(100, 0);
    for(int i=2; i*i<=n; i++){
        if(prime[i] == 0){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 1;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(prime[i] == 0) cout<<i<<" ";
    }cout<<endl;

}
int main(){
    int n;
    cin>>n;
    sieveEratosthenes(n);

    return 0;
}
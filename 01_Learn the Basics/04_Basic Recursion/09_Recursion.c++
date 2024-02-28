//Print Fibonacci Series using iterative , TC: O(n), SC:O(1)

#include<bits/stdc++.h>

using namespace std;
int finonacci(int n){
    int n1=0; 
    int n2=1;
    cout<<n1<<" ";
    cout<<n2<<" ";
    int next_num;
    for(int i=0; i<n-2; i++){
        next_num = n1+n2;
        cout<<next_num<<" ";
        n1=n2;
        n2=next_num;
    }
}
int main(){
    int n;
    cin>>n;
    finonacci(n);

    return 0;
}


//find finonacci of a number using recursion
// #include<bits/stdc++.h>

// using namespace std;

// int fibonacci(int n){
//     //base case
//     if(n<=1) return n;
//     int first_last = fibonacci(n-1);
//     int second_last = fibonacci(n-2);
//     return first_last+second_last;
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<fibonacci(n);
//     return 0;
// }

//TC : O(2^n) near about, SC: O(n) 
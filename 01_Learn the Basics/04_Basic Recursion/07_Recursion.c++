//Factorial of a Number using Recursion

/*
#include<bits/stdc++.h>

using namespace std;
int fact(int n){
    if(n<1) return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}
*/
//Factorial of a Number  using Iterative
#include<bits/stdc++.h>

using namespace std;
int fact(int n){
    int ans=1;
    for(int i=1; i<=n; i++){
        ans*=i;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}
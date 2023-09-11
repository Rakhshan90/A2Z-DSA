//Sum of first N numbers using tail recursion (parameterized recursion)
/*
#include<bits/stdc++.h>

using namespace std;
int sumOfN(int n, int sum){
    if(n<1) return sum;
    sumOfN(n-1, sum+n);
}
int main(){
    int n;
    cin >> n;
    int sum = 0;
    cout<<sumOfN(n, sum);

    return 0;
}
*/

//Sum of first N numbers using functional recursion
#include<bits/stdc++.h>

using namespace std;
int sumOfN(int n){
    if(n==0) return 0;
    return n+sumOfN(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<sumOfN(n);
    return 0;
}
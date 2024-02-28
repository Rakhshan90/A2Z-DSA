//Recursive code for printing numbers from 0 to n

#include<bits/stdc++.h>

using namespace std;
int cnt=0;
void counter(int n){
    if(cnt==n) return;
    cout<<cnt<<" ";
    cnt++;
    counter(n);
}
int main(){
    int n;
    cin>>n;
    counter(n);
    return 0;
}



























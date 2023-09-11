//Problem: Print your Name N times using recursion

#include<bits/stdc++.h>

using namespace std;
void print(int n, int i){
    if(i>n) return;
    cout<<"Rakhshan"<<endl;
    print(n, i+1);
}
int main(){
    int n;
    cin>>n;
    print(n, 1);
    return 0;
}
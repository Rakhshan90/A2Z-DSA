#include<bits/stdc++.h>

using namespace std;

int main(){
    int a = 5;
    int b = 3;

    cout<<"a&b: "<<(a&b)<<endl;
    cout<<"a|b: "<<(a|b)<<endl;
    cout<<"~a: "<<(~a)<<endl;
    cout<<"a^b: "<<(a^b)<<endl;

    //left << and right >> shift operators
    cout<<"5<<1: "<<(5<<1)<<endl;
    cout<<"3<<2: "<<(3<<2)<<endl;
    cout<<"6>>1: "<<(6>>1)<<endl;
    cout<<"6>>2: "<<(6>>2)<<endl;
    cout<<"5>>2: "<<(5>>2)<<endl;
    cout<<"12>>2: "<<(12>>2)<<endl;

    return 0;
}
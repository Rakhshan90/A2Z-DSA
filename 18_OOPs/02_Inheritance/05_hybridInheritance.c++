/*
As we know hybrid inheritance is an example of combination of more than one inheritance
Lets take an example where we will be combining single inheritance and multiple inheritance
*/

#include<bits/stdc++.h>

using namespace std;

class A{
    public:
    int a;
    void getA(){
        cout<<"Enter the value of a: ";
        cin>>a;
    }
};
class B : public A{
    public:
    int b;
    void getB(){
        cout<<"Enter the value of b: ";
        cin>>b;
    }
};
class C{
    public:
    int c;
    void getC(){
        cout<<"Enter the value of c: ";
        cin>>c;
    }
};
class D : public B, public C{
    public:
    void mul(){
        getA();
        getB();
        getC();
        cout<<"Multiplication of a, b, and c is: "<<a*b*c<<endl;
    }
};
int main(){
    D d;
    d.mul();

    return 0;
}
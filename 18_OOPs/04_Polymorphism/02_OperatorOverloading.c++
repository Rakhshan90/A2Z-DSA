/*
Let's see the simple example of operator overloading in C++. In this example, void operator ++ () operator function is defined (inside Test class).

// program to overload the unary operator ++.
*/
/*
#include<bits/stdc++.h>

using namespace std;

class test{
    int num;
    public:
    test(){
        num = 8;
    }
    
    void operator ++(){
        num+=2;
    }
    void display(){
        cout<<"Count is: "<<num<<endl;
    }
};
int main(){
    test obj;
    ++obj;
    obj.display();

    return 0;
}
*/

// Program to overload the binary operators.
#include<bits/stdc++.h>

using namespace std;

class Complex{
    int real, imag;
    public:
    Complex(int real, int imag){
        this->real = real;
        this->imag = imag;
    }
    Complex operator+(Complex &other){
        return Complex(this->real + other.real, this->imag + other.imag);
    }
    void display(){
        cout<<"Complex Number: "<<this->real<<" "<<this->imag<<endl;
    }
};
int main(){
    Complex c1 = Complex(2, 4);
    Complex c2 = Complex(1, 5);
    Complex c3 = c1 + c2;
    c1.display();
    c2.display();
    c3.display();

    return 0;
}
/*
#include<bits/stdc++.h>

using namespace std;

class base1{
    public:
    void display1(){
        cout<<"First Base class"<<endl;
    }
};
class base2{
    public:
    void display2(){
        cout<<"Second Base class"<<endl;
    }
};
class derived : public base1, public base2{
    public:
    void display3(){
        cout<<"Derived class that inherits methods of base1 and base2 class"<<endl;
    }
};
int main(){
    derived d;
    d.display1();
    d.display2();
    d.display3();

    return 0;
}
*/

//Resolve ambiguity using class resolution operator
#include<bits/stdc++.h>

using namespace std;

class A{
    public: 
    void display(){
        cout<<"class A"<<endl;
    }
};
class B{
    public: 
    void display(){
        cout<<"class B"<<endl;
    }
};

class C: public A, public B{
    public:
    void view(){
        A :: display();
    }
};
int main(){
    C obj;
    obj.view();

    return 0;
}
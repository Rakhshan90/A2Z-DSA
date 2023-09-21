#include<bits/stdc++.h>

using namespace std;

class Base{
    public:
    virtual void display() = 0;
};
class Derived : public Base{
    public:
    void display(){
        cout<<"Displaying Derived Class..."<<endl;
    }
};
int main(){
    Derived d;
    Base *ptr = &d;
    ptr->display();

    return 0;
}
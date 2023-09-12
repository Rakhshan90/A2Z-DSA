//Program of copy constructor
#include<bits/stdc++.h>

using namespace std;

class employee{
    public:
    int id;
    //parameterized constructor
    employee(int i){
        id = i;
    }  
    //copy constructor (user defined)
    employee(employee &x){
        id = x.id;
    }
    void display(){
        cout<<id<<endl;
    }
};

int main(){
    employee e1(199);
    employee e2(e1);
    e2.display();
    return 0;
}
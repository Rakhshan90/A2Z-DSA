/*
Let's see another example of C++ class where we are initializing and displaying object through method.
*/
#include<bits/stdc++.h>

using namespace std;

class myClass{
    public:
    int id;
    string name;

    void initialize(int i, string n){
        id = i;
        name = n;
    }
    void display(){
        cout<<"id: "<<id<<", name: "<<name<<endl;
    }
};

int main(){
    myClass obj1;
    myClass obj2;
    obj1.initialize(1, "bravo");
    obj2.initialize(2, "latin");
    obj1.display();
    obj2.display();


    return 0;
}
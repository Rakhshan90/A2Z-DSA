//Default Constructor


#include<bits/stdc++.h>

using namespace std;

class employee{
    public:
    employee(){
        cout<<"Default Constructor invoked!!!"<<endl;
    }
    ~employee(){
        cout<<" Destructor invoked!!!"<<endl;
    }
};
int main(){
    employee e1;
    employee e2;
    return 0;
}


//Parameterized Constructor
/*
#include<bits/stdc++.h>

using namespace std;

class employee{
    public:
    int id;
    string name;

    employee(int i, string n){
        id = i;
        name = n;
    }

    void display(){
        cout<<"id: "<<id<<", name: "<<name<<endl;
    }

};
int main(){
    employee e1 = employee(1, "ahmad");
    employee e2 = employee(2, "rakhshan");

    e1.display();
    e2.display();

    return 0;
}
*/
#include<bits/stdc++.h>

using namespace std;
class employee{
    public:
    int id;
    string name;
    float salary;
    void setter(int id, string name, float salary){
        this->id = id;
        this->name = name;
        this->salary = salary;
    }
    void getter(){
        cout<<"Id: "<<id<<", Name: "<<name<<", Salary: "<<salary<<endl;
    }
};
int main(){
    employee e1;
    employee e2;
    e1.setter(101, "Rakhshan", 10034.100);
    e2.setter(102, "Ahmad", 1007.400);
    e1.getter();
    e2.getter();
    
    return 0;
}
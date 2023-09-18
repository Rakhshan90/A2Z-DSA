/*
Let's see an example of aggregation where Employee class has the reference of Address class as data member. In such way, it can reuse the members of Address class.
*/


#include<bits/stdc++.h>

using namespace std;

class Address{
    public:
    string city, state, country;
    Address(string city, string state, string country){
        this->city = city;
        this->state = state;
        this->country = country;
    }
};
class Employee{
    private:
    Address* address; //Employee HAS-A address
    public:
    string name;
    int id;
    Employee(string name, int id, Address*address){
        this->name = name;
        this->id = id;
        this->address = address;
    }
    void display(){
        cout<<name<<" "<<id<<" "<<address->city<<" "<<address->state<<" "<<address->country<<endl;
    }

};

int main(){
    Address a = Address("Lucknow", "UP", "India");
    Employee e = Employee("Rakhshan", 101, &a);
    e.display();
    
    return 0;
}
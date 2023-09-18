#include<bits/stdc++.h>

using namespace std;

class base{
    public:
    float salary = 150000;
};
class derived1 : public base{
    public:
    int bonus = 1200;
};
class derived2 : public derived1{
    public:
    string name = "Rakhshan";
};
//you can derive more classes further form the previous derived class
int main(){
    derived2 obj;
    cout<<"Name: "<<obj.name<<", Salary: "<<obj.salary<<", Bonus: "<<obj.bonus<<endl;

    return 0;
}
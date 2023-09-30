#include<bits/stdc++.h>

using namespace std;

class employee{
    int empId;
    string empName;
    float empSalary;

    public:
    employee(int empId, string empName, float empSalary){
        this->empId = empId;
        this->empName = empName;
        this->empSalary = empSalary;
    }
    void display(){
        cout<<"Employee Id: "<<this->empId<<", empName: "<<this->empName<<", empSalary: "<<this->empSalary<<endl;
    }
};
int main(){
    employee e1 = employee(101, "Rakhshan", 1200000.99);
    employee e2 = employee(102, "Hassan", 1100000.98);
    e1.display();
    e2.display();
    return 0;
}
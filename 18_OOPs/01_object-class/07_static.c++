/*
#include<bits/stdc++.h>

using namespace std;
class demo{
    public: 
    int accno;
    string name;
    static float rateOfInterest;
    demo(int accno, string name){
        this->accno = accno;
        this->name = name;
    }
    void display(){
        cout<<"accno: "<<accno<<", name: "<<name<<", rateOfInterest: "<<rateOfInterest<<endl;
    }
};
float demo :: rateOfInterest = 22.44;
int main(){
    demo d1 = demo(101, "Rakhshan");
    demo d2 = demo(102, "Ahmad");
    d1.display();
    d2.display();

    return 0;
}
*/

// C++ static field another example: Counting Objects

#include <iostream>  
using namespace std;  
class Account {  
   public:  
       int accno; //data member (also instance variable)      
       string name;   
       static int count;     
       Account(int accno, string name)   
        {    
             this->accno = accno;    
            this->name = name;    
            count++;  
        }    
       void display()    
        {    
            cout<<accno<<" "<<name<<endl;   
        }    
};  
int Account::count=0;  
int main(void) {  
    Account a1 =Account(201, "Sanjay"); //creating an object of Account  
    Account a2=Account(202, "Nakul");   
     Account a3=Account(203, "Ranjana");  
    a1.display();    
    a2.display();    
    a3.display();    
    cout<<"Total Objects are: "<<Account::count;  
    return 0;  
}  

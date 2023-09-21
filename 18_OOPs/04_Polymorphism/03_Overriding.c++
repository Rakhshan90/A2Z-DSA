#include<bits/stdc++.h>

using namespace std;

class Animal{
    public:
    void eat(){
        cout<<"Animal eating..."<<endl;
    }
};
class Dog : public Animal{
    public:
    void eat(){
        cout<<"Dog eating..."<<endl;
    }
};
int main(){
    Dog doggy;
    doggy.eat();
    
    return 0;
}
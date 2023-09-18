#include<bits/stdc++.h>

using namespace std;

class base{
    public:
    int id = 101;
};
class derived1 : public base{
    public:
    string name  = "Rakhshan";
};
class derived2 : public base{
    public:
    float slaray = 192312;
};
class derived3: public base{
    public:
    string role = "Full stack developer";
};
int main(){
    derived1 d1;
    derived2 d2;
    derived3 d3;
    cout<<d1.name<<" "<<d1.id<<endl;
    cout<<d2.slaray<<" "<<d2.id<<endl;
    cout<<d3.role<<" "<<d3.id<<endl;

    return 0;
}
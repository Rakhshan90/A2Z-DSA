#include<bits/stdc++.h>

using namespace std;

class base{
    public:
    int length;
};
class derived : public base{
    public:
    int breadth;
    derived(int l, int b){
        length = l;
        breadth = b;
    }
    void areaOfRectangle(){
        cout<<"Area of rectangle: "<<length*breadth<<endl;
    }
};
int main(){
    derived d = derived(3, 4);
    d.areaOfRectangle();

    return 0;
}
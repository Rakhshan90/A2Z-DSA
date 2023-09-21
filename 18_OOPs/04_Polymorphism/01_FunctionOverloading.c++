//example function overloading with different number of parameters
/*
#include<bits/stdc++.h>

using namespace std;

class calc{
    public:
    int add(int x, int y){
        cout<<"addition of two numbers: "<<x+y<<endl;
    }
    int add(int x, int y, int z){
        cout<<"addition of three numbers: "<<x+y+z<<endl;
    }
};
int main(){
    calc *obj = new calc();
    obj->add(5, 10);
    obj->add(10, 15, 20);

    return 0;
}
*/

//example function overloading with different types of parameters
#include<bits/stdc++.h>

using namespace std;
class calc{
    public:
    int mul(int x, int y){
        cout<<"Multiplication of two numbers: "<<x*y<<endl;
    }
    float mul(double x, int y){
        cout<<"Multiplication of two numbers: "<<x*y<<endl;
    }
};
int main(){
    calc *obj = new calc();
    obj->mul(1, 2);
    obj->mul(5.44, 1);

    return 0;
}
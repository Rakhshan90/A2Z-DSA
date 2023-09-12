//shallow copy 

/*
#include<bits/stdc++.h>

using namespace std;

class Demo{
    int a;
    int b;
    int *p;

    public:
    Demo(){
        p = new int;
    }
    void setter(int x, int y, int z){
        a = x;
        b = y;
        *p = z;
    }
    void getter(){
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<*p<<endl;
        cout<<&(*p)<<endl;
    }

    
};
int main(){
    Demo d1;
    d1.setter(4, 5, 10);
    d1.getter();
    Demo d2 = d1;
    d2.getter();

    
    return 0;
}
*/

//Deep copy
#include<bits/stdc++.h>

using namespace std;

class Demo{
    int a;
    int b;
    int *p;

    public:
    Demo(){
        p = new int;
    }
    //user defined copy constructor
    Demo(Demo &i){
        a = i.a;
        b = i.b;
        p = new int;
        *p = *(i.p);
    }

    void setter(int x, int y, int z){
        a = x;
        b = y;
        *p = z;
    }
    void getter(){
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<*p<<endl;
        cout<<&(*p)<<endl;
    }

    
};
int main(){
    Demo d1;
    d1.setter(4, 5, 10);
    d1.getter();
    Demo d2 = d1;
    d2.getter();

    
    return 0;
}
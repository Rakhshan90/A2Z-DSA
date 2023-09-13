// Program to print box length using friend function

/*

#include<bits/stdc++.h>

using namespace std;

class Box{
    private:
    int length;
    public:
    friend int printLength(Box);
};
int printLength(Box b){
    b.length=10;
    return b.length;
}

int main(){
    Box b;
    cout<<"Length of the box: "<<printLength(b)<<endl;
    return 0;
}
*/

// Let's see a simple example when the function is friendly to two classes.
#include <bits/stdc++.h>

/*

using namespace std;
class B; // forward declaration
class A
{
    int x;

public:
    void setData(int i)
    {
        x = i;
    }
    friend int min(A, B);
};
class B
{
    int y;

public:
    void setData(int i)
    {
        y = i;
    }
    friend int min(A, B);
};
// Now define friend function that will be friendly for both two classes.
int min(A a, B b)
{
    if (a.x <= b.y)
    {
        cout << a.x << endl;
    }
    else
    {
        cout << b.y << endl;
    }
}
int main()
{
    A a;
    a.setData(10);
    B b;
    b.setData(20);
    min(a, b);

    return 0;
}
*/

//Let's see a simple example of a friend class.
#include<bits/stdc++.h>

using namespace std;
class A{
    int x=5;
    friend class B;
};
class B{
    public:
    void display(A &a){
        cout<<"The value of x is: "<<a.x<<endl;
    }
};
int main(){
    A a;
    B b;
    b.display(a);

    return 0;
}
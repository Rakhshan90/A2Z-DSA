/*
Let's see an example of class that has two fields: id and name. It creates instance of the class, initializes the object and prints the object value.
*/
#include <bits/stdc++.h>

using namespace std;

class myClass
{
public:
    int id;
    string name;
};

int main()
{
    myClass obj;
    obj.id = 123;
    obj.name = "bravo";
    cout << obj.id << endl;
    cout << obj.name << endl;

    return 0;
}
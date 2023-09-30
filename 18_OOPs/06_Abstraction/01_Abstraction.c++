#include<bits/stdc++.h>

using namespace std;

class shape{
    public:
    virtual void draw() = 0;
};
class rectangle : public shape{
    public:
    void draw(){
        cout<<"Reactangle..."<<endl;
    }
};
int main(){
    rectangle r;
    r.draw();
    return 0;
}
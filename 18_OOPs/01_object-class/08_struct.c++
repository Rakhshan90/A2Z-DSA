#include<bits/stdc++.h>

using namespace std;

struct rectangle{
    int width, height;
    rectangle(int w, int h){
        width = w; height = h;
    }
    void findRectangle(){
        cout<<"Rectangle: "<<(width*height)<<endl;
    }

};
int main(){
    struct rectangle obj = rectangle(5, 6);
    obj.findRectangle();
    
    return 0;
}
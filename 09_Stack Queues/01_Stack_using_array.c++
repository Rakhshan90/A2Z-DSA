#include<iostream>

using namespace std;
class stack{
    //stack properties
    public:
    int top;
    int *arr;
    int size;

    stack(int size){
        this->size = size;
        top = -1;
        arr = new int[this->size];
    }
void push(int element){
    //check if stack have some space then insert
    if(size - top > 1){
        top++;
        arr[top] = element;
    }
    else{
        cout<<"stack is overflow"<<endl;
    }
}
void pop(){
    //check if stack have value then remove
    if(top >= 0){
        top--;
    }
    else{
        cout<<"stack is underflow"<<endl;
    }
}
int peek(){
    if(top>=0){
        return arr[top];
    }
    else{
        cout<<"stack is empty"<<endl;
        return -1;
    }
}
bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}
};

int main(){
    stack s(5);
    s.push(4);
    s.push(5);
    s.push(3);

    cout<<"top element: "<<s.peek();
    s.pop();
    cout<<endl;
    cout<<"top element: "<<s.peek();
    s.pop();
    cout<<endl;
    cout<<"top element: "<<s.peek();
    s.pop();
    cout<<endl;
    cout<<"top element: "<<s.peek();
    cout<<endl;

    s.push(42);
    cout<<"top element: "<<s.peek();
    cout<<endl;
    if(s.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }

    return 0;
}
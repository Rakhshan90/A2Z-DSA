/* 
stack : Container 4
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> st;

    // st.push(10);
    st.emplace(20);

    // int top = st.top();
    // st.pop();
    // cout<<top<<endl;

    stack<int>st1;
    st1.emplace(5);
    swap(st1, st);    //alternative syntax st1.swap(st)

    cout<<st1.top()<<endl;
    cout<<st.top()<<endl;
    //size and empty functions are same as vector

    return 0;
}
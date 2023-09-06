/* 
Queue : Container 5
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q;
    
    q.push(5);
    q.emplace(10);

    q.back()+=5; 
    cout<<q.back()<<endl; //this will print 15 

    cout<<q.front()<<endl;


    // q.pop();
    // cout<<q.front()<<endl;

    //size and empty functions are same as vector



    return 0;
}
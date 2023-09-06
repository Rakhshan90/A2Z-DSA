/* 
Priority Queue : Container 6
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    //max heap
    priority_queue<int> pq;
    
    pq.push(1);     //{1}
    pq.push(5);     //{5 1}
    pq.emplace(10); //{10 5 1}
    pq.emplace(8);  //{10 8 5 1}
    pq.pop();       //{8 5 1}

    // cout<<pq.top()<<endl;

    //min heap
    priority_queue<int, vector<int>, greater<int> > min;
    min.emplace(5);  //{5}
    min.push(10);    //{5 10}
    cout<<min.top()<<endl;

    //swap size empty functions are same as vector


    return 0;
}
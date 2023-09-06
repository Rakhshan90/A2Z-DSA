/*
dequeue : Container 3
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(1);
    dq.push_front(2);
    dq.emplace_front(10);
    dq.emplace_back(20);

    dq.pop_back();
    dq.pop_front();

    for(auto it : dq){
        cout<<it<<" ";
    }

    //rest functions same as vector
    //rbegin, rend, end, begin, empty, clear, insert, erase, size, swap, back, front

    return 0;
}
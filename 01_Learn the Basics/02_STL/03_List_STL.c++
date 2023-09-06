/*
list : Container 2

A list in STL is a contiguous container that allows the inserting and erasing of elements in constant time and iterating in both directions.
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    list<int> li;
    li.push_back(1);
    li.push_front(2);
    li.emplace_back(5);
    li.emplace_front(4);

    li.pop_back();
    li.pop_front();

    li.sort();
    // li.reverse();

    for(auto it : li){
        cout<<it<<" ";
    }

    //rest functions same as vector
    //rbegin, rend, end, begin, empty, clear, insert, erase, size, swap, back, front

    return 0;
}
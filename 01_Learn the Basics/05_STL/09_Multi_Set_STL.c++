/* 
Set : Container 8

A multiset in STL is an associative container just like a set the only difference is it can store duplicate elements in it.
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    multiset<int> ms;
    ms.insert(1);
    ms.emplace(1);
    ms.emplace(1); //{1, 1, 1}

    // ms.erase(1);  //all 1's erased 
    ms.erase(ms.find(1));   //only single 1 erased
    
    //rest all functions are same as set

    for(auto it:ms){
        cout<<it<<endl;
    }
    

    return 0;
}
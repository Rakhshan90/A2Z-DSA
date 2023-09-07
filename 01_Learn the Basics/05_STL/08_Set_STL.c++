/* 
Set : Container 7

A set in STL is a container that stores unique elements in a particular order. Every operation on a set takes O(1) complexity in the average case and takes O(n) in the worst case.
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    set<int> set;
    set.insert(1);
    set.emplace(5);
    set.emplace(4);
    set.emplace(3);   
    set.emplace(2);   //{1, 2, 3, 4, 5}

    // auto it = set.begin();
    // cout<<*(it)<<endl;
    // cout<<&(it)<<endl;

    //count method used to check presence of element in set
    // cout<<set.count(5)<<endl;   // 1

    // set.erase(4);           //{1, 2, 3, 5}

    //find used to point address of specific element in set
    // auto it = set.find(2); 
    // set.erase(it);          //{1, 3, 5}

    //{1, 2, 3, 4, 5}
    // auto it1 = set.find(1);
    // auto it2 = set.find(4);
    // set.erase(it1, it2);  // {4, 5};  

    for(auto it : set){
        cout<<it<<" ";
    }
    cout<<endl;
    

    //rest functions same as vector
    //rbegin, rend, end, begin, empty, clear, size, swap, clear

    /*
    lower bound of x is the smallest index where value is >= x
    upper bound of x is the smallest index where value is > x
    */
   auto it3 = set.upper_bound(2);
   cout<<*(it3)<<endl;

   auto it4 = set.lower_bound(2);
   cout<<*(it4)<<endl;

    return 0;
}
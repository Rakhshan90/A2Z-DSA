/*
map : Container 10

map in STL are associative containers where each element consists of a key value and a mapped value. Two mapped values cannot have the same key value.

TC: O(log n)

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //  key, value
    map<int, int> mp1;
    mp1[1] = 2;         //{1:2}
    mp1.insert({2, 3}); //{1:2, 2:3}
    mp1.emplace(3, 5);  //{1:2, 2:3, 3:5 }

    // cout<<mp1[3]<<endl;
    // mp1.erase(1); // 2 will erased
    for (auto it : mp1)
    {
        cout << it.first << " " << it.second << endl;
    }

    ///////////////////////////////////////////////
    // **** rest all functions are same as set ****
    ///////////////////////////////////////////////

    //  key,     {val, val}
    map<int, pair<int, int>> mp2;
    mp2[1] = {2, 4}; //{1: {2, 4}}
    for (auto it : mp2)
    {
        cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    }

    //      {key, key} , val
    map<pair<int, int>, int> mp3;
    mp3[{1, 2}] = 4; //{{1,2} : 4}
    mp3[{4, 5}] = 10; //{{1,2} :4, {4, 5}: 10}
    for (auto it : mp3)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }

    /*
    multimap in STL are associative containers like maps where each element consists of a key value and a mapped value, the only difference is multimaps can store duplicate elements
    */

   /*
   unordered_map in STL are associative containers where each element consists of a key value and a mapped value. Two mapped values cannot have the same key value. The elements can be in any order.
   TC: O(1) avg case
   TC: O(n) worst case but in some cases
   */

    return 0;
}
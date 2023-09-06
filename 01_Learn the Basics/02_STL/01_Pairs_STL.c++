/*
What is C++ STL?

STL is one of the unique abilities of C++ which makes it stand out from every other programming language. STL stands for standard template library which contains a lot of pre-defined templates in terms of containers and classes which makes it very easy for developers or programmers to implement different data structures easily without having to write complete code and worry about space-time complexities.

STL divided into four parts:
1.Algorithms
2.Functions
3.Containers
4.Iterators


*/

/*
Pairs are the part of utility library. Piars are not containers
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    //{1, 4}
    // pair<int, int> p = {1, 4};
    // cout<<p.first<<" "<<p.second<<endl;

    //{1, 4, 5}
    // we will use nested pair property
    pair<int, pair<int, int>> p = {1, {4, 5}};
    cout << p.first << " " << p.second.first << " " << p.second.second << endl;

    //we can create pair array for storing pair values at each index
    pair<int, int> arr[] = {{1, 2}, {4, 5}, {3, 6}};
    cout<<arr[0].first<<" "<<arr[2].second<<endl;

    return 0;
}
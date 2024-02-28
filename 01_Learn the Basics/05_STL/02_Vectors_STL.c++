/*
Vectors : Container 1

Vectors in STL are basically dynamic arrays that have the ability to change size whenever elements are added or deleted from them. Vector elements can be easily accessed and traversed using iterators. A vector stores elements in contiguous memory locations.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.emplace_back(2); // same as push_back but faster.

    vector<pair<int, int>> v2;
    v2.push_back({3, 5});
    v2.emplace_back(3, 4);

    vector<int> v3(5, 100); // v3 has size 5 with five times 100 instances are stored
    vector<int> v4(5);      // v4 has size 5

    vector<int> v5(v3); // copying vector 3 into vector 5

    // iterator
    //  vector<int>::iterator it = v1.begin();
    //  it++;
    // it points the address where the value is stored in memory
    //  cout<<&(it)<<endl;
    // it will print the value where it is stored in memory
    //  cout<<*(it)<<endl;

    // it will point the address right after the last value is stored in memory
    //  vector<int>::iterator it = v1.end();

    // not used
    //  vector<int>::iterator it = v1.rend();
    //  vector<int>::iterator it = v1.rbegin();

    // access element in same way like array
    //  cout<<v1[0]<<" "<<v1[1]<<endl;

    // To Print entire vector
    // for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }
    // cout << endl;
    // shorthand to print entire vector using auto keyword
    // for (auto it = v1.begin(); it != v1.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }

    // **** extreme shorthand to print entire vector [!important] **** //
    // for (auto it : v1)
    // {
    //     cout<<it<<" ";
    // }

    vector<int> vec;
    vec.emplace_back(12);
    vec.emplace_back(25);
    vec.emplace_back(35);
    vec.emplace_back(22);
    vec.emplace_back(10);

    // vec.erase(vec.begin()+4); //[12, 25, 35, 22]
    // vec.erase(vec.begin()+1, vec.begin()+4); //[12, 10]
    // for(auto it : vec){
    //     cout<<it<<" ";
    // }
    
    //insert function
    vector<int> vec1(2, 100); //{100, 100}
    vec1.insert(vec1.begin(), 10); //{10, 100, 100}
    vec1.insert(vec1.begin()+1, 2, 20); //{10, 20, 20, 100, 100}
    vector<int>copy(2, 50); //{50, 50}
    vec1.insert(vec1.begin(), copy.begin(), copy.end()); //{50, 50, 10, 20, 20, 100, 100}
    // for(auto it : vec1){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    //other ibuilt functions 
    // vec1.pop_back();
    // for(auto it : vec1){
    //     cout<<it<<" ";
    // }

    // cout<<vec1.size()<<endl;
    // cout<<vec1.empty()<<endl;
    // vec.clear();
    // cout<<vec1.front()<<endl;
    // cout<<vec1.back()<<endl;

    vector<int> vec3(2, 10);
    vector<int> vec4(2, 100);
    swap(vec3, vec4); // vec3 = {100, 100}, vec4 = {10, 10}


    return 0;
}
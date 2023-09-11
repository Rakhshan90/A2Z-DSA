//find frequencies of numbers in array

/*
int arry can be declared upto max size 1e6 inside main function, 1e7 globally.
bool array can be declared upto max size 1e7 inside main function, 1e8 globally.

If we need to use hashing for 1e9 values, we cannot use array.

Thereby, we need to use hashMap: hashMap is basically a map/unordered_map that hashed with values.

Benefit of hashMap:  if we want store frequency of 13 we need to declare atleast arr with size 13. but with hashMap, we will only storing frequency of 13 that means, size of the hashMap will be 1.
*/

//    key, value                          key, value
//map<int, int> hashMap, or unordered_map<int, int> hashMap
//    num, frequency                      num, frequency    [when we do hashing]

#include<bits/stdc++.h>

using namespace std;

void frequency(int arr[], int n){
    // unordered_map<int, int> hashMap;
    map<int, int> hashMap;
    for(int i=0; i<n; i++){
        hashMap[arr[i]] ++;
    }
    //fetch
    for(auto it: hashMap){
        cout<<"number: "<<it.first<<" "<<"frequency: "<<it.second<<endl;
    }
}
int main(){
    int arr[10] = {2, 1, 4, 4 , 1, 1, 5, 7, 9, 10};
    frequency(arr, 10);
    return 0;
}
//All Kind of Patterns in Recursion | Print All | Print one | Count
/*
[Pattern: Print All]
Problem statement: Print all the subsequences of array whose sum equal to k. Remember you can take non-contiguous portion of array as well. 
*/

//Intuition: All the Patterns will be Based on the approach of Include and Exclude call that we use in subsequences/subsets 


/*
Approach: Using Recursion and Backtracking
1. Keep making exluding calls, when you are not including the current element unitl the base condition fullfilled.
2. keep making including calls, when you are including the current element unitl the base condition fullfilled, also make sure to add current element to the sum and store current element into ds.
3. Once index reaches the end of the array, base condition will fullfilled. check if current sum is equal k, we have got the subsequence in ds just print the ds.
4. return in both case either we got the subsequence or we didn't got the subsequence.
5. When you returning (backtracking) pop the current element from the ds, remove the current element from the sum. [We are performing backtracking to get possible subsequences]
*/

/*
#include<bits/stdc++.h>

using namespace std;
void recursion(int index, int sum, vector<int> &ds, vector<int> arr, int k){
    if(index >= arr.size()){
        if(sum ==  k){
            for(int i=0; i<ds.size(); i++){
                cout<<ds[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }


    //include call
    ds.push_back(arr[index]);
    sum+=arr[index];
    recursion(index+1, sum, ds, arr, k);
    //backtracking
    sum-=arr[index];
    ds.pop_back();

    //exclude call
    recursion(index+1, sum, ds, arr, k);

}
int main(){
    int k; 
    cin>>k;
    int n;
    cin>>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int index = 0, sum = 0;
    vector<int> ds;
    recursion(index, sum, ds, arr, k);

    return 0;
}
*/

/*
[Pattern: Print one]
Problem statement: Print only one subsequence of array whose sum equal to k. Remember you can take non-contiguous portion of array as well. 
*/

/*
Approach: Using Recursion and Backtracking
1. Approach will be same but here since we need only one subsequence. So, if base condition satisfied, return ture otherwise return false.
2. When you make recursion call, make sure to check if recursive call gives you true that means we already have got a subsequence return true no more recursion calls needed.
3. else, recursive calls gives you false that means we don't get a subsequence yet keep making recursive calls. At the end if we don't get true we will return false.
*/

/*

#include<bits/stdc++.h>

using namespace std;
bool recursion(int index, int sum, vector<int> &ds, vector<int> arr, int k){
    if(index >= arr.size()){
        //condition satisfied
        if(sum ==  k){
            for(int i=0; i<ds.size(); i++){
                cout<<ds[i]<<" ";
            }
            cout<<endl;
            return true;
        }
        //condition not satisfied
        else return false;
    }


    //include call
    ds.push_back(arr[index]);
    sum+=arr[index];
    if(recursion(index+1, sum, ds, arr, k) == true) return true;
    //backtracking
    sum-=arr[index];
    ds.pop_back();

    //exclude call
    if(recursion(index+1, sum, ds, arr, k) == true) return true;

    return false;

}
int main(){
    int k; 
    cin>>k;
    int n;
    cin>>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int index = 0, sum = 0;
    vector<int> ds;
    recursion(index, sum, ds, arr, k);

    return 0;
}

*/


/*
[Pattern: return count]
Problem statement: return count of  all the subsequences of array whose sum equal to k. Remember you can take non-contiguous portion of array as well. 
*/
/*
Approach: Using Recursion and Backtracking
1. Approach will be same but here since we need only count of all subsequences. So, if base condition satisfied, return 1 otherwise return 0.
2. store the count in a variable left, that will returned by left recursion call.
3. store the count in a variable right, that will returned by right recursion call.
4. return left+right as total count of all subsequences.
*/
#include<bits/stdc++.h>

using namespace std;
int recursion(int index, int sum, vector<int> arr, int k){
    if(index >= arr.size()){
        //condition satisfied
        if(sum ==  k) return 1;
        //condition not satisfied
        else return 0;
    }


    //include call
    sum+=arr[index];
    int right = recursion(index+1, sum, arr, k);
    //backtracking
    sum-=arr[index];

    //exclude call
    int left = recursion(index+1, sum, arr, k);
    
    return left+right;

}
int main(){
    int k; 
    cin>>k;
    int n;
    cin>>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int index = 0, sum = 0;
    vector<int> ds;
    cout<<recursion(index, sum, arr, k);

    return 0;
}

//TC: O(2^n), SC: O(n)
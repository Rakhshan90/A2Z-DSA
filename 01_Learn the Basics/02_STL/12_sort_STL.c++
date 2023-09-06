#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int, int>p1, pair<int, int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    //if they are same
    if(p1.first>p2.first) return true;
    else false;
}

int main(){
    int arr[5] = {8, 4, 3, 2, 1};
    // sort(arr, arr+n); //normal array
    //sort(arr.begin(), arr.end());

    //To sort in descending order
    // sort(arr, arr+n, greater<int>);

    // pair<int, int> arr[] = {{1,2}, {2, 1}, {4, 1}};

    ///////////////////////////////
    //***** my way sorting ***** //
    ///////////////////////////////

    /*sort it according to second element but, if second element are same then sort it according to first element in descending order
    */
    //sort(arr, arr+n, comp);  //{{4, 1}, {2, 1}, {1, 2}}

    //To find number of 1 bits
    int num = 7;
    int cnt = __builtin_popcount(num) ;
    cout<<cnt<<endl;

    // long long num = 1231230192810211;
    // int cnt = __builtin_popcountll(num);

    // To find print all permutations
    string s="123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));

    //To find max and min element in array
    //maxi = *max_element(arr, arr+n)
    int maxi = *max_element(arr, arr+5);
    cout<<"Max: "<<maxi<<endl;

    //mini = *min_element(arr, arr+n);
    int mini = *min_element(arr, arr+5);
    cout<<"Min: "<<mini<<endl;

    //To find sum of array of elements
    int sum = accumulate(arr, arr+5, 0);
    cout<<"Sum: "<<sum<<endl;

    return 0;
}
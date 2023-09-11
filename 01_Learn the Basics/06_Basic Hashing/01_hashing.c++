//find frequencies of numbers in array

#include<bits/stdc++.h>

using namespace std;

void frequency(int arr[], int n){
    //hash array
    int hash[n+1]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    //fetch
    for(int i=0; i<n+1; i++){
        cout<<i<<" "<<hash[i]<<endl;
    }
}

int main(){
    int arr[10] = {2, 1, 4, 4 , 1, 1, 5, 7, 9, 10};
    frequency(arr, 10);
    return 0;
}
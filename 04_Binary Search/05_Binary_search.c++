#include<iostream>

using namespace std;

int BinarySearch(int arr[], int n, int element){
    int low, high, mid;
    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        else if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2, 6, 7, 8, 12, 44, 67, 88, 90, 92};
    int n=sizeof(arr)/sizeof(int);
    int element=90;
    int SearchIndex=BinarySearch(arr, n, element);
    cout<<"The Element "<<element<<" at index "<<SearchIndex;
    return 0;
}
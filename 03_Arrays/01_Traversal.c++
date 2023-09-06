#include<iostream>

using namespace std;
void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {21, 34, 1, 5, 6, 10, 14, 33, 50 , 90, 22};
    int size=sizeof(arr)/sizeof(int);
    display(arr, size);
    return 0;
}
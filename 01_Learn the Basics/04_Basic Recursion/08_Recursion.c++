// Reverse array using iterative(two pointer)
/*
#include<bits/stdc++.h>

using namespace std;

void reverseArray(int arr[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    reverseArray(arr, 5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
*/

// Reverse array using recursion
#include <bits/stdc++.h>

using namespace std;

void reverseArray(int arr[], int n, int s, int e)
{
    if (s < e)  //this is our base case
    {
        swap(arr[s], arr[e]);
        reverseArray(arr, n, s+1, e-1);
    }
}
int main()
{
    int n=5;
    int arr[n] = {5, 4, 3, 2, 1,};
    reverseArray(arr, n, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
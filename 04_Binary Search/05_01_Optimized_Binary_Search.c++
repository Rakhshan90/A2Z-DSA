// Optimized form of binary search
#include <iostream>

using namespace std;
int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start) / 2; //--optimized formula
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else // arr[mid]>key
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter size of an array"<<endl;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter element that you want to find"<<endl;
    cin>>key;
    int ans = binarySearch(arr, n, key);
    cout<<key<<" at index "<<ans<<endl;
    return 0;
}
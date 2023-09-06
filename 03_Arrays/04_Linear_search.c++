#include <iostream>

using namespace std;
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
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
    int search = linearSearch(arr, n, key);
    cout <<key<<" at index "<<search<<endl;
    return 0;
}
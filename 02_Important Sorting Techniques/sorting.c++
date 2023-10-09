#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j <= n - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false)
            break;
        cout << "run" << endl;
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
            cout << "run" << endl;
        }
    }
}

void merge(vector<int> &arr, int low, int high, int mid)
{
    vector<int> temp; 
    int left = low; //starting index of left half of arr
    int right = mid + 1; //starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left //
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void merge_sort(vector<int> &arr, int low, int high)
{

    // base case
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);      // dividing left part
    merge_sort(arr, mid + 1, high); // dividing right part

    merge(arr, low, high, mid);     // merging sorted halves
}

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int left=low;
    int right=high;

    while(left<right){
        while(left<=high-1 && arr[left]<=pivot){
            left++;
        }
        while(right>=low-1 && arr[right]>pivot){
            right--;
        }
        if(left<right) swap(arr[left], arr[right]);
    }
    swap(arr[right], arr[low]);
    return right;  //pivot index
}
void quickSort(vector<int> &arr, int low, int high){
    if(low<high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}
int main()
{
    int n;
    cin >> n;
    // int *arr = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    // insertion_sort(arr, n);


    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // merge_sort(arr, 0, n-1);
    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
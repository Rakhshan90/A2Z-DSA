#include <iostream>

using namespace std;
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int insert(int arr[], int n, int element, int index, int capacity)
{
    if (n >= capacity)
    {
        cout<<"Cannot insert element due to lack of capacity of array"<<endl;
        return -1;
    }
    else
    {
        for (int i = n - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int index, element;
    cin >> index;
    cin>>element;
    int capacity = 10;
    insert(arr, n, element, index, capacity);
    n += 1;
    display(arr, n);

    return 0;
}
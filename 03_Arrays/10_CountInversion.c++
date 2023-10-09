/*
Problem Statement: There is an integer array 'A' of size 'N'. Number of inversions in an array can be defined as the number of pairs of 'i' and 'j' such that 'i' < 'j' and 'A[i]' > 'A[j]'. You must return the number of inversions in the array. 
In other words, inversion count indicates how far(or close) the array is from being sorted.
*/


/*
Approach 1: Brute force approach
1. First, we will run a loop(say i) from 0 to N-1 to select the first element in the pair.
2. As index j should be greater than index i, inside loop i, we will run another loop i.e. j from i+1 to N-1.
3. Inside this second loop, we will check if a[i] > a[j] i.e. if a[i] and a[j] can be a pair. 4. If they satisfy the condition, we will increase the count by 1.
5. Finally, we will return the count i.e. the number of such pairs.

TC:O(n^2), SC:O(1)
*/

/*
Approach 2: Using Merge sort with some modification
*/
/*
int merge(vector<int>&a, int low, int mid, int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left++]);
        }
        else{
            cnt+=(mid-left+1);
            temp.push_back(a[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(a[left++]);
    }
    while(right<=high){
        temp.push_back(a[right++]);
    }

    for(int i=low; i<=high; i++){
        a[i] = temp[i-low];
    }

    return cnt;
}
int mergeSort(vector<int>&a, int low, int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = low+(high-low)/2;
    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid+1, high);
    cnt +=  merge(a, low, mid, high);

    return cnt;
}
int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n-1);
}
*/
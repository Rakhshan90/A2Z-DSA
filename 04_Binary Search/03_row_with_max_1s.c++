/*
Problem statement: You are given a 2D matrix 'ARR' (containing either 'O' or '1) of size
'N' x 'M', where each row is in sorted order.
Find the O-based index of the first row with the maximum number of 1's.

If two rows have the same number of 1's, return the row with a lower index.
If no row exists where at-least one '1' is present, return -1.
*/

/*
Approach 1: Linear search (Brute force)
1. First, we will declare 2 variables i.e. cnt_max(initialized with 0), and index(initialized with -1). The first variable will store the maximum number of 1’s we have got and the ‘index’ will store the row number.
2. Next, we will start traversing the matrix. We will use a loop(say i) to select each row at a time.
3. Now, for each row i, we will use another loop(say j) and count the number of 1’s in that row.
4. After that, we will compare it with cnt_max and if the current number of 1’s is greater, we will update cnt_max with the current no. of 1’s and ‘index’ with the current row index.
5. Finally, we will return the variable ‘index’. It will store the index of the row with the maximum no. of 1’s. And otherwise, it will store -1.

TC:O(n*m), SC:O(1)
*/
/*
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1, max_cnt = 0;
    for(int row=0; row<n; row++){
        int cnt_one = 0;
        for(int col=0; col<m; col++){
            cnt_one += matrix[row][col];
            if(cnt_one > max_cnt){
                max_cnt = cnt_one;
                index = row;
            }
        }
    }
    return index;
}
*/

/*
Approach 2: Applying Binary search on each row
We cannot optimize the row traversal but we can optimize the counting of 1’s for each row.
Instead of counting the number of 1’s, we can use the following formula to calculate the number of 1’s:
Number_of_ones = m(number of columns) – first occurrence of 1(0-based index).

As, each row is sorted, we can find the first occurrence of 1 in each row using any of the following approaches:

lowerBound(1) 
upperBound(0) 
firstOccurrence(1) 

Here, we are going to use the lowerBound() function to find the first occurrence.

1. we will start traversing the rows. We will use a loop(say i) to select each row at a time.
2. Now, for each row i, we will use lowerBound() to get the first occurrence of 1. Now, using the following formula we will calculate the number of 1’s:
Number_of_ones = m(number of columns) – lowerBound(1)(0-based index).
3. After that, we will compare it with cnt_max and if the current number of 1’s is greater, we will update cnt_max with the current no. of 1’s and ‘index’ with the current row index.
4. Finally, we will return the variable ‘index’. It will store the index of the row with the maximum no. of 1’s. And if the matrix does not contain any 1, it stores -1.

TC:O(n*log m), SC:O(1)
*/

/*
int lowerBound(vector<int> arr, int n, int x) {
	int ans = -1;
	int low=0, high=n-1;
	int mid = low+(high-low)/2;
	while(low<=high){
		if(arr[mid]>=x){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
		mid = low+(high-low)/2;
	}
	if(ans==-1) return n;
	return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1, max_cnt = 0;
    for(int row=0; row<n; row++){
        int cnt_one = m - lowerBound(matrix[row], n, 1);
        if(cnt_one > max_cnt){
            max_cnt = cnt_one;
            index = row;
        }
    }
    return index;
}
*/

/*
To Write less code we can also use in-built lower_bound() function of c++ to calculate lower bound of 1. 
*/
/*
#include<bits/stdc++.h>
int lowerBound(vector<int> arr, int n, int x) {
	int ans = -1;
	ans = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	if(ans==-1) return n;
	return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1, max_cnt = 0;
    for(int row=0; row<n; row++){
        int cnt_one = m - lowerBound(matrix[row], n, 1);
        if(cnt_one > max_cnt){
            max_cnt = cnt_one;
            index = row;
        }
    }
    return index;
}
*/
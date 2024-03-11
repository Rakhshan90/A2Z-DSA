/*
Problem statement: You are given a row-wise sorted matrix 'mat' of size m x n where 'm' and 'n' are the numbers of rows and columns of the matrix, respectively.
Your task is to find and return the median of the matrix.
Note:
'm' and 'n' will always be odd.
Example:
Input: 'n' = 5, 'm' = 5
'mat' = 
[     [ 1, 5, 7, 9, 11 ],
      [ 2, 3, 4, 8, 9 ],
      [ 4, 11, 14, 19, 20 ],
      [ 6, 10, 22, 99, 100 ],
      [ 7, 15, 17, 24, 28 ]   ]

Output: 10
Explanation: If we arrange the elements of the matrix in the sorted order in an array, they will be like this-
1 2 3 4 4 5 6 7 7 8 9 9 10 11 11 14 15 17 19 20 22 24 28 99 100 
So the median is 10, which is at index 12, which is midway as the total elements are 25, so the 12th index is exactly midway. Therefore, the answer will be 10. 
*/

/*
Approach 2: Efficient Approach (Using Binary Search)

Count Smaller or Equal Elements (cntSmallerEquals):
Objective:
The cntSmallerEquals function counts the number of elements less than or equal to a given value x in a 2D matrix.

Algorithm:
Iterate through each row of the matrix.
For each row, use the upperBound function to find the count of elements less than or equal to x in that row.
Sum up the counts for all rows and return the total count.

Main Function (median):
Objective:
The median function aims to find the median of the 2D matrix.

Initialization:
Initialize low to the minimum value in the matrix and high to the maximum value in the matrix.
Calculate the desired count req as half of the total number of elements in the matrix.

Binary Search:
Use binary search to find the median value.
For each iteration, calculate the count of elements less than or equal to the current mid-value using cntSmallerEquals.
Adjust the search space based on the comparison of the count with the desired count (req).
Update low or high accordingly.

Result:
The final result is stored in low, which represents the median value.


TC: O(row*log col) dur to upperBound function, SC: O(1)
*/

/*
int upperBound(vector<int> arr, int x){
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int cntSmallerEquals(vector<vector<int>> &matrix, int x){
    int cnt = 0;
    for(int row=0; row<matrix.size(); row++){
        cnt += upperBound(matrix[row], x);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX;
    int high = INT_MIN;
    for(int row=0; row<m; row++){
        low = min(low, matrix[row][0]);
        high = max(high, matrix[row][n-1]);
    }
    int req = (m*n)/2;
    while(low <= high){
        int mid = (low + high) / 2;
        int smallerEquals = cntSmallerEquals(matrix, mid);
        if(smallerEquals <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
*/
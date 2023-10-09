/*
Problem statement: You are given a O-indexed 2-D grid 'g' of size 'n' X 'm', where each
cell contains a positive integer, and adjacent cells are distinct. You need to find the location of a peak element in it. If there are multiple answers, find any of them.
A peak element is a cell with a value strictly greater than all its adjacent cells.
Assume the grid to be surrounded by a perimeter of '-1s'.
You must write an algorithm that works in O(n * log(m)) or O(m * log(n)) complexity.
*/


/*
Approach: Applying Binary search on cols.

Intution : We are applying binary search on columns to get the row index of largest element of mid column. Once we got largest element, we simply compare it with it's previous mid column and it's next mid column just like we do in approach of finding peak element in 1-D array, if it's is greater than both we will return cell of that element.

1. Find mid col by applying binary search on columns.
2. Find row index of largest element of mid col. 
3. To find left value we will check if previos col index on same row index is under the boundary then the left value will be at same row index but previous mid column otherwise -1.
4. To find right value we will check if next col index on same row index is under the boundary then the right value will be at same row index but next mid column otherwise -1.
5. if mat[rowIndex][mid_col] > left && mat[rowIndex][mid_col] > right we have found the peak element return it's cell {rowIndex, mid_col}
6. else if mat[rowIndex][mid_col] < left, peak element will be present at left part, so eliminate right half.
7. else, peak element will be present at right part, so eliminate left half.
 
TC:O(n * log(m)), where n is total rows and m is total cols, SC:O(1)
*/
/*
int findMax(vector<vector<int>> &g, int rows, int col){
    int maxVal = -1, index = -1;
    for(int row=0; row<rows; row++){
        if(g[row][col] > maxVal){
            maxVal = g[row][col];
            index = row;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g){
    int rows = g.size(), cols = g[0].size();
    int low = 0, high = cols-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        int rowIndex = findMax(g, rows, mid);
        int left = mid-1 >= 0 ? g[rowIndex][mid-1] : -1;
        int right = mid+1 < cols ? g[rowIndex][mid+1] : -1;
        if(g[rowIndex][mid] > left && g[rowIndex][mid] > right) return {rowIndex, mid};
        else if(g[rowIndex][mid] < left) high = mid - 1 ;
        else low = mid + 1;
    }  
    return {-1, -1}; //dummy statement
}
*/
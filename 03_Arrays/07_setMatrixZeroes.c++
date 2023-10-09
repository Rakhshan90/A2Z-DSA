/*
Problem Statement: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.
*/

/*
Approach 1: By using two extra arrays
1. First, we will declare two arrays: a row array of size rows and a col array of size cols and both are initialized with 0.
2. Then, we will use two loops(nested loops) to traverse all the cells of the matrix.
3. If any cell (i,j) contains the value 0, we will mark ith index of row array i.e. row[i] and jth index of col array col[j] as 1. It signifies that all the elements in the ith row and jth column will be 0 in the final matrix.
4. We will perform step 3 for every cell containing 0.
5. Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for which either row[i] or col[j] is marked as 1.
6. Thus we will get our final matrix.
TC: O(m*n), SC:O(m+n). But, since we need to solve it in place so we will try optimized approach 
*/
/*
void solve(vector<vector<int>>& matrix, int rows, int cols, 
    vector<int> &rowArr, vector<int> &colArr){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == 0){
                    rowArr[i] = 1;
                    colArr[j] = 1;
                }
            }
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(rowArr[i] == 1 || colArr[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>rowArr(rows, 0);
        vector<int>colArr(cols, 0);
        solve(matrix, rows, cols, rowArr, colArr);
    }
*/

/*
Approach 2: 
1. Prepare two hash arrays, col hash array from matrix[0][1] to matrix[0][n-1] with col0 variable to server the purpose of col hash array. row hash array from matrix[0][0] to matrix[m-1][0] to server the purpose of row hash array, to store which rows and columns contain a zero, respectively, and Iterate over the matrix and mark the rows and columns that contain a zero in the hash arrays.

2. Iterate over the matrix except hashed arrays and set all elements in the rows and columns that were marked in the hash arrays to zero.

3. Process hash col hash arr before processing row hash arr: col hash arr depends on the martix[0][0], if matrix[0][0] contain 0 then mark the whole col hashed arr to 0 except the variable col0.
row hash arr depends on the col0 variable, if col0 contain 0 then mark the whole row hashed arr to 0.

TC:O(m*n), SC:O(1)
*/

/*
void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        //step 1: Prepare two hash arrays in matrix itself
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    //rowArr
                    matrix[i][0] = 0;
                    if(j == 0) col0 = 0;
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        //step 2: Process non hashed arrays cells
        for(int i=matrix.size()-1; i>=1; i--){
            for(int j=matrix[0].size()-1; j>=1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //step 3: Process col hashed array before row hashed array
        if(matrix[0][0] == 0){
            for(int j=1; j<matrix[0].size(); j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }
*/
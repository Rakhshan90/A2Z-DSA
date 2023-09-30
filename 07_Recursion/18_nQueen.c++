/*
Problem statement: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

/*
Approach 1: Recursion and Backtracking
1. Use a recursive backtracking algorithm to explore all possible placements of queens on the chessboard.
2. Start by placing a queen in the first column.
3. For each row in the first column, check if it is safe to place a queen there. If it is, place the queen in that row and recursively explore all possible placements of queens on the remaining columns.
4. If no safe placement is found for a queen in the current column, backtrack and try the other other row of the column.
5. Repeat steps 3 and 4 until all queens have been placed on the chessboard. 

TC: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N!).
SC: O(N) due to the space used by the board, ans, and the recursive call stack.
*/

/*
bool isSafe(int col, int row, vector<string> &board, int n){
        int copyRow = row;
        int copyCol = col;
        //Upper Left Diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = copyRow;
        col = copyCol;
        //Left Direction
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = copyRow;
        col = copyCol;
        //Lower Left Diagonal
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;

    }
    void search(int col, int n, vector<string> &board, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(col, row, board, n)){
                board[row][col] = 'Q';
                search(col+1, n, board, ans);
                //backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        search(0, n, board, ans);
        return ans;
    }
*/


/*
Approach 2: Recursion and Backtracking with hashing (Optimized)
Intuition: This is the optimization of the issafe function. In the previous issafe function, we need o(N) for a row, o(N) for the column, and o(N) for the diagonal. Here, we will use hashing to maintain a list to check whether that position can be the right one or not.

TC: Exponential in nature since we are trying out all ways, to be precise it is O(!N)
SC: O(N) due to the space used by the board, ans, and the recursive call stack.
*/

/*
void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, 
    vector<int> &leftRow, vector<int> &leftDownDiagonal, vector<int> &leftUpDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(leftRow[row] == 0 && leftDownDiagonal[row+col] == 0 && leftUpDiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                leftDownDiagonal[row+col] = 1;
                leftUpDiagonal[n-1+col-row] = 1;
                solve(col+1, n, board, ans, leftRow, leftDownDiagonal, leftUpDiagonal);
                //Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                leftDownDiagonal[row+col] = 0;
                leftUpDiagonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        //Hashing arrays
        vector<int>leftRow(n, 0), leftDownDiagonal(2*n - 1, 0), leftUpDiagonal(2*n - 1, 0); 
        solve(0, n, board, ans, leftRow, leftDownDiagonal, leftUpDiagonal);
        return ans;
    }
*/
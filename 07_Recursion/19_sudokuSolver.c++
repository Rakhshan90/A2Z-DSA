/*
Problem statement: Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

/*
Intuition:
Since we have to fill the empty cells with available possible numbers and we can also have multiple solutions, the main intuition is to try every possible way of filling the empty cells. And the more correct way to try all possible solutions is to use recursion. In each call to the recursive function, we just try all the possible numbers for a particular cell and transfer the updated board to the next recursive call.

Approach: Recursion and Backtracking 
1. Use a recursive backtracking algorithm to explore all possible assignments of digits to the empty cells in the Sudoku grid.
2. Start by trying to assign a digit to the first empty cell.
3. For each digit from 1 to 9, check if it is valid to assign that digit to the current cell. If it is, assign the digit to the cell and recursively explore all possible assignments of digits to the remaining empty cells.
4. If no valid assignment is found for the current cell, backtrack and try assigning a different digit to the cell.
5. Repeat steps 3 and 4 until all empty cells have been filled with valid digits.
*/

/*
bool isValid(int row, int col, vector<vector<char>>& board, char ch){
        for(int i=0; i<9; i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++){
                if(board[row][col] == '.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(isValid(row, col, board, ch)){
                            board[row][col] = ch;
                            if(solve(board) == true) return true;
                            //backtrack
                            else board[row][col] = '.'; 

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
*/
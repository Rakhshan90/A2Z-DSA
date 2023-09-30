/*
Problem statement: Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

/*
Approach: Recursion and Backtracking
Step 1: Find the first character of the given string.

Step 2: Start Backtracking in all four directions until we find all the letters of sequentially adjacent cells.

Step 3: At the end, If we found our result then return true else return false.

Edge cases: Now think about what will be our stopping condition, we can stop or return false if we reach the end of the boundaries of the matrix or the letter at which we are making recursive calls is not the required letter.

We will also return if we found all the letters of the given word i.e. we found the number of letters equal to the length of the given word.
As, we cannot reuse a cell again. so, we are going to mark visited cells with some random character that will prevent us from revisiting them again and again.

TC: O(m*n*4^k), SC: O(k), where k is the length of the given word.
*/

/*
bool search(int index, int row, int col, vector<vector<char>>& board, string word){
        if(index>=word.length()) return true;

        if((row<0 || row==board.size()) || (col<0 || col==board[0].size()) || 
        board[row][col] == '#' || board[row][col] != word[index]) return false;

        //to prevent from reusing the same char again
        char c = board[row][col];
        board[row][col] = '#';

        //Four directions
        bool top = search(index+1, row-1, col, board, word);
        bool bottom = search(index+1, row+1, col, board, word);
        bool left = search(index+1, row, col-1, board, word);
        bool right = search(index+1, row, col+1, board, word);

        //undo the changes
        board[row][col] = c;

        return top || bottom || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++){
                if(search(0, row, col, board, word)) return true;
            }
        }
        return false;
    }
*/
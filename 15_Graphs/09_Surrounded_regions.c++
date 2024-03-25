/*
Problem statement: Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/

/*
Intuition:.
The boundary elements in the matrix cannot be replaced with ‘X’ as they are not surrounded by ‘X’ from all 4 directions. This means if ‘O’ (or a set of ‘O’) is connected to a boundary ‘O’ then it can’t be replaced with ‘X’. 

The intuition is that we start from boundary elements having ‘O’ and go through its neighboring Os in 4 directions and mark them as visited to avoid replacing them with ‘X’. 

Approach:
We can follow either of the traversal techniques as long as we are starting with a boundary element and marking all those Os connected to it. We will be solving it using DFS traversal, but you can apply BFS traversal as well. 

DFS is a traversal technique that involves the idea of recursion.. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes.

The algorithm steps are as follows:

Create a corresponding visited matrix and initialize it to 0.
Start with boundary elements, once ‘O’ is found, call the DFS function for that element and mark it as visited. In order to traverse for boundary elements, you can traverse through the first row, last row, first column, and last column. 
DFS function call will run through all the unvisited neighboring ‘O’s in all 4 directions and mark them as visited so that they are not converted to ‘X’ in the future. The DFS function will not be called for the already visited elements to save time, as they have already been traversed. 
When all the boundaries are traversed and corresponding sets of ‘O’s are marked as visited, they cannot be replaced with ‘X’. All the other remaining unvisited ‘O’s are replaced with ‘X’. This can be done in the same input matrix as the problem talks about replacing the values, otherwise tampering with data is not advised. 

Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M), For the worst case, every element will be marked as ‘O’ in the matrix, and the DFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. Also, we are running loops for boundary elements so it will take O(N) + O(M).

Space Complexity ~ O(N x M), O(N x M) for the visited array, and auxiliary stack space takes up N x M locations at max. 
*/

/*
class Solution {
private:
   void dfs(int row, int col, vector<vector<int>> &vis, 
   vector<vector<char>>& board, int m, int n, int delRow[], int delCol[]){
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if((nRow >=0 && nRow < m) && (nCol >=0 && nCol < n) && 
            !vis[nRow][nCol] && board[nRow][nCol] == 'O')
                dfs(nRow, nCol, vis, board, m, n, delRow, delCol);
        }
   }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        // first row and last row
        for(int j=0; j<n; j++){
            if(!vis[0][j] && board[0][j] == 'O') 
                dfs(0, j, vis, board, m, n, delRow, delCol);

            if(!vis[m-1][j] && board[m-1][j] == 'O') 
                dfs(m-1, j, vis, board, m, n, delRow, delCol);
        }

        // first col and last col
        for(int i=0; i<m; i++){
            if(!vis[i][0] && board[i][0] == 'O') 
                dfs(i, 0, vis, board, m, n, delRow, delCol);

            if(!vis[i][n-1] && board[i][n-1] == 'O') 
                dfs(i, n-1, vis, board, m, n, delRow, delCol);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
*/
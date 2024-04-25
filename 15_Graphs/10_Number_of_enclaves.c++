/*
Problem statement: You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

/*
Intuition:
The land cells present in the boundary cannot be counted in the answer as we will walk off the boundary of the grid. Also, land cells connected to the boundary land cell can never be the answer. 

The intuition is that we need to figure out the boundary land cells, go through their connected land cells and mark them as visited. The sum of all the remaining land cells will be the answer.

Approach: Same approach that we have used to solve the problem called "Surrounded regions"

TC: O(N * M), SC: O(N * M)
*/

/*
class Solution {
private:
void dfs(int row, int col, vector<vector<int>> &vis, 
        vector<vector<int>>& grid, int m, int n, int delRow[], int delCol[]){
            vis[row][col] = 1;
            for(int i=0; i<4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if((nRow >= 0 && nRow < m) && (nCol >= 0 && nCol < n) && 
                !vis[nRow][nCol] && grid[nRow][nCol] == 1)
                    dfs(nRow, nCol, vis, grid, m, n, delRow, delCol);
            }
        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // first row and last row
        for(int j=0; j<n; j++){
            if(!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, vis, grid, m, n, delRow, delCol);

            if(!vis[m-1][j] && grid[m-1][j] == 1)
                dfs(m-1, j, vis, grid, m, n, delRow, delCol);
        }

        // first col and last col
        for(int i=0; i<m; i++){
            if(!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, vis, grid, m, n, delRow, delCol);

            if(!vis[i][n-1] && grid[i][n-1] == 1)
                dfs(i, n-1, vis, grid, m, n, delRow, delCol);
        }

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
*/
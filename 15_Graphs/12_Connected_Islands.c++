/*
Problem statement: Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
*/

/*
Approach: DFS traversal 

Intuition: Try to think of all the elements as a node or a vertex, we can observe they are connected in some way as all 8 directions connectivity is allowed. If we start a traversal algorithm, from a particular 1 (land) it will make sure it traverses the nearest 1 (land). So, one traversal with a starting point will cover an island. If we do 3 traversals then we will have 3 starting nodes, anyone can be considered as a starting node in an island, and make sure it visits everyone. In the following example, if we take 3 starting nodes we will be able to touch all the pieces of land. Hence, one starting node makes sure it touches all the connected lands. The basic idea is that “one starting node represents one island”.  So, we just need to figure out the number of starting points.

The algorithm steps are as follows:

1. Creates a vis grid to track visited cells, marking all as unvisited. Defines displacement arrays delRow and delCol to move in 8 possible directions (up, down, left, right, and diagonals). Sets a counter cnt to 0 to count the islands.
2. Iterates through each cell in the grid.
3. For an unvisited cell with a '1': Increments cnt, indicating a new island found. Calls a Depth-First Search (dfs) function to explore the island.
4. Marks the current cell as visited in vis. Recursively explores its 8 neighbors:
5. If a neighbor is within grid bounds, unvisited, and contains a '1': Calls dfs recursively for that neighbor to continue exploring the island.
6. The cnt variable, incremented for each distinct island, holds the final count.

Time Complexity ~ O(NxM + NxMx9), NxM for the nested loops, and NxMx9 for the overall DFS of the matrix, that will happen throughout if all the cells are filled with 1. overall TC: O(NxM)

Space Complexity: O(NxM) for visited array and recursive stack space. 
*/

/*
class Solution {
  private:
  void dfs(int row, int col, vector<vector<char>>& grid, int rows, int cols, 
  vector<vector<int>>& vis, int delRow[], int delCol[]){
      vis[row][col] = 1;
      for(int i=0; i<8; i++){
          int nRow = row + delRow[i];
          int nCol = col + delCol[i];
          if((nRow >=0 && nRow < rows) && (nCol >=0 && nCol < cols) && 
          !vis[nRow][nCol] && grid[nRow][nCol] == '1'){
              dfs(nRow, nCol, grid, rows, cols, vis, delRow, delCol);
          }
      }
  }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int> (m, 0));
        int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int cnt = 0;
        // traversing first row and last row
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid, n, m, vis, delRow, delCol);
                }
            }
        }
        return cnt;
    }
};
*/
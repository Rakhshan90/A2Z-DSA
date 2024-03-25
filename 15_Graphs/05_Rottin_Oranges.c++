/*
Problem statement: Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
*/

/*
Intuition: 
The idea is that for each rotten orange, we will find how many fresh oranges there are in its 4 directions. If we find any fresh orange we will make it into a rotten orange. One rotten orange can rotten up to 4 fresh oranges present in its 4 directions. For this problem,  we will be using the BFS ( Breadth-First Search ) technique.

Approach: BFS algorithm
First step:
1. We will create a Queue data structure to store coordinate of Rotten Oranges
2. We will traverse the whole grid, push all the rotten oranges only in the queue and mark those rotten oranges visited.
3. We will also keep track of freshOranges.

Second step:
1. Now while our queue is not empty,  we will pick up each Rotten Orange and check in all its 4 directions whether a Fresh orange is present or not. If it is present we will make it rotten and push it in our queue data structure and pop out the Rotten Orange which we took up as its work is done now. Also we will keep track of the count of rotten oranges we are getting.
2. If we rotten some oranges, then obviously our queue will not be empty. In that case, we will increase our total time. This goes on until our queue becomes empty. 

Thired step: 
1. After it becomes empty, We will check whether the total number of freshOranges is equal to the total number of rottinOranges. If yes, we will return the total time taken, else will return -1 because some fresh oranges are still left and can’t be made rotten.

TC: O(m*n), SC: O(m*n)
*/

/*
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // {{row, col}, time}
        queue<pair<pair<int, int>, int>>q;
        int vis[m][n];
        int freshOranges = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
                if(grid[i][j] == 1) freshOranges++; 
            }
        }
        
        int totalTime = 0;
        int rottinOranges = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            totalTime = max(totalTime, t);
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if((nRow >= 0 && nRow < m) && (nCol >= 0 && nCol < n) 
                && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                    q.push({{nRow, nCol}, t+1});
                    vis[nRow][nCol] = 2;
                    rottinOranges++;
                }
            }
        }
        if(freshOranges == rottinOranges) return totalTime;
        else return -1;
    }
};
*/
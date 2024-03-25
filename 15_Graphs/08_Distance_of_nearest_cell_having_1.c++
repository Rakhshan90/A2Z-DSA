/*
Problem statement: Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell. The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.
*/

/*
Intuition:
Breadth First Search, BFS, is a traversal technique where we visit the nodes level-wise, i.e., it visits the same level nodes simultaneously, and then moves to the next level. 

The intuition is that BFS will take a step from cells containing 1 and will reach out to all zeros that are at a distance of one. Apparently, we can say that the nearest 1 to the 0s is at a distance of one. Again if we take another step, we will reach the next set of zeros, for these zeros 1 is at a distance of two. If we continue the same, till we can go, we can reach all the 0’s possible. 

We will choose the BFS algorithm as it moves step by step and we want all of them to traverse in a single step together so that we can have a minimum count with us.

Approach:
Initial configuration:
Queue: Define a queue and insert the pair of starting nodes’ coordinates along with the steps (<coordinates, step>). For example, ((2, 1), 2) means cell (2, 1) is the source node and the nearest 1 can be found at a distance of 2 from the node.
Visited array: an array initialized to 0 indicating unvisited nodes.  
Distance matrix: stores the distance of the nearest cell having 1 for every particular cell.
The algorithm steps are as follows:

Push the pair of starting points and its steps (<coordinates, stept>) in the queue, and mark the cell as visited.
Start the BFS traversal, pop out an element from the queue every time, and travel to all its unvisited neighbors having 0. 
For every neighboring unvisited 0, we can mark the distance to be +1 of the current node distance and store it in the distance 2D array, and at the same time insert <{row, col}, steps+1> into the queue.
Repeat the steps until the queue becomes empty and then return the distance matrix where we have stored the steps.


Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, the BFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M) + O(N x M) ~ O(N x M)

O(N x M) for the visited array, distance matrix, and queue space takes up N x M locations at max. 
*/

/*
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    queue<pair<pair<int, int>, int>> q;  // {{row, col}, steps}
	    vector<vector<int>> vis(m, vector<int>(n, 0));
	    vector<vector<int>> dist(m, vector<int>(n, 0));
	    
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	            else vis[i][j] = 0;
	        }
	    }
	    
	    int delRow[] = {-1, 0, 1, 0};
	    int delCol[] = {0, 1, 0, -1};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        dist[row][col] = steps;
	        for(int i=0; i<4; i++){
	            int nRow = row + delRow[i];
	            int nCol = col + delCol[i];
	            
	            if((nRow >= 0 && nRow < m) && (nCol >=0 && nCol < n) 
	            && vis[nRow][nCol] == 0){
	                vis[nRow][nCol] = 1;
	                q.push({{nRow, nCol}, steps + 1});
	            }
	        }
	    }
	    
	    return dist;
	}
};
*/
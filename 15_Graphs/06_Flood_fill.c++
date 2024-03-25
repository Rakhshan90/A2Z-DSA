/*
Problem statement: An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.
*/

/*
Approach: DFS algorithm
Initial DFS call will start with the starting pixel (sr, sc) and make sure to store the initial colour. 
Now, either we can use the same matrix to replace the colour of all of the aforementioned pixels with the newColor or create a replica of the given matrix. It is advised to use another matrix because we work on the data and not tamper with it. So we will create a copy of the input matrix. 
Check for the neighbours of the respective pixel that has the same initial colour and has not been visited or coloured. DFS call goes first in the depth on either of the neighbours.
We go to all 4 directions and check for unvisited neighbours with the same initial colour. To travel 4 directions we will use nested loops, you can find the implementation details in the code. 
DFS function call will make sure that it starts the DFS call from that unvisited neighbour, and colours all the pixels that have the same initial colour, and at the same time it will also mark them as visited. 

Time Complexity: O(NxM + NxMx4) ~ O(N x M)
For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.
Space Complexity: O(N x M) + O(N x M)
O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 
*/

/*
class Solution {
private:
   void dfs(int sr, int sc, vector<vector<int>>& image, 
   vector<vector<int>>& ans, int delRow[], int delCol[], int initialVal, int color){
        int m = image.size();
        int n = image[0].size();
        ans[sr][sc] = color;
        for(int i=0; i<4; i++){
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if((nRow >=0 && nRow < m) && (nCol >=0 && nCol < n) && 
            image[nRow][nCol] == initialVal && ans[nRow][nCol] != color){
                dfs(nRow, nCol, image, ans, delRow, delCol, initialVal, color);
            }
        }

   }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialVal = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, ans, delRow, delCol, initialVal, color);
        return ans;
    }
};
*/
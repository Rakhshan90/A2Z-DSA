/*
Problem statement:
You are given a N*N maze with a rat placed at mat[0][0]. Find all paths that rat can follow to reach its destination i.e. mat[N-1] [N-1]. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). In the given maze, each cell can have a value of either O or 1. Cells with a value of O are considered blocked, which means the rat cannot enter or traverse through them. On the other hand, cells with a value of 1 are open, indicating that the rat is allowed to enter and move through those cells.
*/

/*
Approach: Recursion and Backtracking
1. Check if the current position is safe. This means that the current position is within the bounds of the maze, is not visited before, and is not blocked. 
2. if step 1 is valid then made current possible movement and mark current position as visited.
3. Base condition: If the current position is the destination, add the current path to the answer list.
4. Otherwise, Recursively explore all possible paths from the current position in the following order:
Down
Up
Right
Left
5. While exploring any particular path make sure to add movement to the path that you will make.
6. After exploring any particular path backtrack to find more paths, if possible.
7. After exploring all possible paths from the current position, mark the current position as unvisited.

TC: O(4^(n)), because on every cell we need to try 4 different directions.

SC:  O(n), Maximum Depth of the recursion tree(auxiliary space).
*/


/*
bool isSafe(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis){
    if( (row>=0 && row < mat.size()) && (col>=0 && col < mat.size()) && vis[row][col]==0 && 
    mat[row][col] == 1) return true;
    else return false;
}
void findPaths(int row, int col, vector<vector<int>> &mat, string &path, 
vector<string> &ans, vector<vector<int>> &vis){
    if(row == mat.size()-1 && col == mat.size()-1){
        ans.push_back(path);
        return;
    }

    vis[row][col] = 1;
    
    //Down Movement
    if(isSafe(row+1, col, mat, vis)){
        path.push_back('D');
        findPaths(row+1, col, mat, path, ans, vis);
        //backtrack
        path.pop_back();
    }


    //Up Movement
    if(isSafe(row-1, col, mat, vis)){
        path.push_back('U');
        findPaths(row-1, col, mat, path, ans, vis);
        //backtrack
        path.pop_back();
    }

    //Right Movement
    if(isSafe(row, col+1, mat, vis)){
        path.push_back('R');
        findPaths(row, col+1, mat, path, ans, vis);
        //backtrack
        path.pop_back();
    }

    //Left Movement
    if(isSafe(row, col-1, mat, vis)){
        path.push_back('L');
        findPaths(row, col-1, mat, path, ans, vis);
        //backtrack
        path.pop_back();
    }
    //backtrack
    vis[row][col] = 0;
}
vector<string> ratMaze(vector<vector<int>> &mat) {
    vector<string> ans;
    string path = "";
    vector<vector<int>> vis = mat;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            vis[i][j] = 0;
        }
    }
    findPaths(0, 0, mat, path, ans, vis);
    return ans;
}
*/
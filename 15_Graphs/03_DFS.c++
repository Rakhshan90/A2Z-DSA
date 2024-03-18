/*
Depth First Search Traversal:
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

Approach: 
DFS is a traversal technique which involves the idea of recursion and backtracking. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes. 

1. In DFS, we start with a node ‘v’, mark it as visited and store it in the solution vector. It is unexplored as its adjacent nodes are not visited.
2. We run through all the adjacent nodes, and call the recursive dfs function to explore the node ‘v’ which has not been visited previously. This leads to the exploration of another node ‘u’ which is its adjacent node and is not visited. 
3. The adjacency list stores the list of neighbours for any node. Pick the neighbour list of node ‘v’ and run a for loop on the list of neighbours (say nodes ‘u’ and ‘w’ are in the list). We go in-depth with each node. When node ‘u’ is explored completely then it backtracks and explores node ‘w’.
4. This traversal terminates when all the nodes are completely explored. 
In this way, all the nodes are traversed in a depthwise manner.

TC: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
SC: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.
*/

/*
class Solution {
  private:
  void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
      vis[node] = 1;
      ls.push_back(node);
      for(auto it : adj[node]){
          if(!vis[it]) dfs(it, adj, vis, ls);
      }
  }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ls;
        int vis[V] = {0};
        dfs(0, adj, vis, ls);
        return ls;
    }
};
*/
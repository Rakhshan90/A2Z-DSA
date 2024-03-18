/*
Problem statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.
Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
*/

/*
Approach: We know about both the traversals, Breadth First Search (BFS) and Depth First Search (DFS). We can use any of the traversals to solve this problem because a traversal algorithm visits all the nodes in a graph. In any traversal technique, we have one starting node and it traverses all the nodes in the graph. Suppose there is an ‘N’ number of provinces so we need to call the traversal algorithm ‘N‘ times, i.e., there will be ‘N’ starting nodes. So, we just need to figure out the number of starting nodes.

The algorithm steps are as follows:

1. We need a visited array initialized to 0, representing the nodes that are not visited.
2. Run the for loop looping from 0 to N, and call the DFS for the first unvisited node. 
3. DFS function call will make sure that it starts the DFS call from that unvisited node, and visits all the nodes that are in that province, and at the same time, it will also mark them as visited. 
4. Since the nodes traveled in a traversal will be marked as visited, they will no further be called for any further DFS traversal. 
5. Keep repeating these steps, for every node that you find unvisited, and visit the entire province. 
6. Add a counter variable to count the number of times the DFS function is called, as in this way we can count the total number of starting nodes, which will give us the number of provinces.

TC: O(N) + O(N+2E), SC: O(N)
*/

/*
class Solution {
  private: 
  void dfs(int node, vector<int> adjList[], int vis[]){
      vis[node] = 1;
      for(auto it:adjList[node]){
          if(!vis[it]) dfs(it, adjList, vis);
      }
  }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        //create adjacency list 'adjList' from given adjacency matrix 'adj'
        vector<int> adjList[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int provinces = 0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                provinces++;
                dfs(i, adjList, vis);
            }
        }
        return provinces;
    }
};
*/
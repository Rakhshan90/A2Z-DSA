/*
Problem statement: Given an undirected graph of 'V' vertices and 'E' edges. Return true if the graph contains a cycle or not, else return false.
Note:
There are no self-loops(an edge connecting the vertex to itself) in the given graph.
*/

/*
Intuition: The intuition is that we start from a node, and start doing BFS level-wise, if somewhere down the line, we visit a single node twice, it means we came via two paths to end up at the same node. It implies there is a cycle in the graph because we know that we start from different directions but can arrive at the same node only if the graph is connected or contains a cycle, otherwise we would never come to the same node again.  

Approach 1: Using BFS
1. For BFS traversal, we need a queue data structure and a visited array. 
2. Push the pair of the source node and its parent data (<source, parent>) in the queue, and mark the node as visited. The parent will be needed so that we don’t do a backward traversal in the graph, we just move frontwards. 
3. Start the BFS traversal, pop out an element from the queue every time and travel to all its unvisited neighbors using an adjacency list.
4. Repeat the steps either until the queue becomes empty, or a node appears to be already visited which is not the parent, even though we traveled in different directions during the traversal, indicating there is a cycle.
5. If the queue becomes empty and no such node is found then there is no cycle in the graph.
A graph can have connected components as well. In such cases, if any component forms a cycle then the graph is said to have a cycle.

Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
*/

/*
class Graph {
private:
bool bfs(int src, vector<int> adj[], int vis[]){
    queue<pair<int, int>> q; //{node, parent}
    vis[src] = 1;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto neighbor : adj[node]){
            if(!vis[neighbor]){
                vis[neighbor] = 1;
                q.push({neighbor, node});
            }
            else if(neighbor != parent) return true;
        }
    }
    return false;
}
public:
    bool detectCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(bfs(i, adj, vis) == true) return true;
            }
        }
        return false;
    }
};
*/

/*
Intuition:
The cycle in a graph starts from a node and ends at the same node. DFS is a traversal technique that involves the idea of recursion and backtracking. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes. The intuition is that we start from a source and go in-depth, and reach any node that has been previously visited in the past; it means there’s a cycle.

Approach 2: Using DFS
1. In the DFS function call make sure to store the parent data along with the source node, create a visited array, and initialize to 0. The parent is stored so that while checking for re-visited nodes, we don’t check for parents. 
2. We run through all the unvisited adjacent nodes using an adjacency list and call the recursive dfs function. Also, mark the node as visited.
3. If we come across a node that is already marked as visited and is not a parent node, then keep on returning true indicating the presence of a cycle; otherwise return false after all the adjacent nodes have been checked and we did not find a cycle.

Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.
*/

/*
class Graph {
private:
   bool dfs(int src, int parent, vector<int> adj[], int vis[]){
       vis[src] = 1;
       for(auto neighbor : adj[src]){
           if(!vis[neighbor]){
               if(dfs(neighbor, src, adj, vis) == true) return true;
           }
           else if(neighbor != parent) return true;
       }
       return false;
   }
public:
    bool detectCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis) == true) return true;
            }
        }
        return false;
    }
};
*/
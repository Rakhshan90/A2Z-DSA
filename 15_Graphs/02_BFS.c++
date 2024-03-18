/*
Breadth First Search Traversal:
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Approach:
Initial Configuration:
1. Queue data structure: follows FIFO, and will always contain the starting.
2. Visited array: an array initialized to 0
3. In BFS, we start with a “starting” node, mark it as visited, and push it into the queue data structure.
4. In every iteration, we pop out the node ‘v’ and put it in the solution vector, as we are traversing this node.
5. All the unvisited adjacent nodes from ‘v’ are visited next and are pushed into the queue. The list of adjacent neighbors of the node can be accessed from the adjacency list.
6. Repeat steps 2 and 3 until the queue becomes empty, and this way you can easily traverse all the nodes in the graph.
In this way, all the nodes are traversed in a breadthwise manner.

TC: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
SC: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
*/

/*
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int> q;
        int vis[V] = {0};
        vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
*/
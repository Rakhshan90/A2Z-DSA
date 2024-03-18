/*
The space needed to represent a graph using its adjacency matrix is n² locations. Space complexity = (n*n), It is a costly method as n² locations are consumed.
*/

/*
// Adjacency matrix
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n), space complexity: O(n*n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}
*/


/*
In the previous storing method, we saw it was taking n² space to store the graph, this is where the adjacency list comes into the picture, it takes a very less amount of space.
*/

/*
// Adjacency list for undirected graph
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E), space complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
*/


/*
// Adjacency list for undirected graph
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for directed graph
    // time complexity: O(E), space complexity: O(E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        // u —> v
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return 0;
}
*/
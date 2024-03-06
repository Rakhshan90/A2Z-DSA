/*
Problem statement: You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
Each minute, a node becomes infected if:
The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.
*/

/*
Approach: BFS(level order traversal)
Step 1: Create Parental Node Map with BFS:
Initialize a queue and a parent hashmap to store the parent of each node.
Insert the root node into the queue.
While the queue is not empty, pop the front node of the queue, set its parents as the popped node, and insert the children back into the queue.

Step 2: Locate the Start Node:
If a reference to the start node is provided, use the given reference node. If only the value of the start node is given, perform any traversal method (inorder, postorder, preorder, or bfs) to find the node with the given value. Store the reference of the found node in the ‘startNode’ node pointer.

Step 3:  Perform a DFS traversal from the start node to nodes to find time for entire tree to be infected:
Initialize a queue and a visited hashmap.
Insert the start node into the queue and initialize the time from start ‘time’ as 0.
While the queue is not empty, pop the front node.
Push its non-visited adjacent nodes (parent, left child, right child) back into the queue. Mark the adjacent nodes as visited and increment the time from the start by one.

Step 4: Return the time-1, which is total time for tree to be infected.
*/

/*
Time Complexity: O(3N + log N ) The time complexity arises from traversing the tree to create the parent hashmap, which involves visiting every node once hence O(N), exploring all nodes to get infected which will be O(N) in the worst case, exploring all nodes to find startNode which will be in O(N) in the worst case, and the logarithmic lookup time for the hashmap is O( log N) in the worst scenario as well hence O(N + N + N + log N) which simplified to O(N).

Space Complexity: O(N) The space complexity stems from the data structures used, O(N) for the parent hashmap, O(N) for the queue of DFS, and O(N) for the visited hashmap hence overall our space complexity is O(3N) ~ O(N).
*/

/*
void findParent(TreeNode*root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*current = q.front();
            q.pop();
            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    TreeNode* findStart(TreeNode*root, int start){
        if(!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode*current = q.front();
                q.pop();
                if(current->val == start){
                    return current;
                }
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }
        return nullptr;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        unordered_map<TreeNode*, TreeNode*> parent_track;
        findParent(root, parent_track);
        TreeNode*startNode = findStart(root, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        int time = 0;
        q.push(startNode);
        visited[startNode] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode*current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            time++;
        }
        return time-1;
    }
*/
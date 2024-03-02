/*
Problem statement: Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order. 
*/

/*
Approach: BFS(level order traversal)
Step 1: Create Parental Node Map with BFS:
Initialize a queue and a parent hashmap to store the parent of each node.
Insert the root node into the queue.
While the queue is not empty, pop the front node of the queue, set its parents as the popped node, and insert the children back into the queue.

Step 2: Locate the Target Node:
If a reference to the target node is provided, use the given reference node. If only the value of the target node is given, perform any traversal method (inorder, postorder, or preorder) to find the node with the given value. Store the reference of the found node in the ‘target’ node pointer.

Step 3:  Perform a DFS traversal from the target node to find nodes at distance ‘K’:
Initialize a queue and a visited hashmap.
Insert the target node into the queue and initialize the distance from target ‘dis’ as 0.
While the queue is not empty, pop the front node.
Push its non-visited adjacent nodes (parent, left child, right child) back into the queue. Mark the adjacent nodes as visited and increment the distance from the target ‘dis’ by one.
If the distance from the target node is equal to K then add the node to the list of nodes at distance K (result array).

Step 4: Return the list of nodes found at distance ‘K’ from the target node.
*/

/*
Time Complexity: O(2N + log N ) The time complexity arises from traversing the tree to create the parent hashmap, which involves visiting every node once hence O(N), exploring all nodes at a distance of ‘K’ which will be O(N) in the worst case, and the logarithmic lookup time for the hashmap is O( log N) in the worst scenario as well hence O(N + N + log N) which simplified to O(N).

Space Complexity: O(N) The space complexity stems from the data structures used, O(N) for the parent hashmap, O(N) for the queue of DFS, and O(N) for the visited hashmap hence overall our space complexity is O(3N) ~ O(N).
*/

/*
void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        findParent(root, parent_track);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        int dist = 0;
        q.push(target);
        visited[target] = true;
        while(!q.empty()){
            int size = q.size();
            if(dist == k) break;
            dist++;
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
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
*/
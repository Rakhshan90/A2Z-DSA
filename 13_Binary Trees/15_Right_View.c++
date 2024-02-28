/*
Problem statement: Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

/*
Approach: BFS level order traversal
BFS Level-Order Traversal:
1. Use a queue (q) to perform a level-order traversal of the binary tree.
2. Maintain a map (nodes) to store the rightmost node at each level along with its level.
3. Initialize the queue with the root node and level 0.
Process each node in the queue:
4. If the level is not present in the map, add the current node's value to the map for that level.
5. Enqueue the right child first (if it exists) and then the left child (if it exists).
Extract Right Side View:
6. After the level-order traversal is complete, extract the values of the rightmost nodes from the map and store them in the result vector (ans).

TC: O(N), SC: O(N)
*/

/*
vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode*, int>> q;
        map<int, int> nodes;
        q.push({root, 0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int level = front.second;
            TreeNode* node = front.first;
            if(nodes.find(level) == nodes.end()){
                nodes[level] = node->val;
            }
            if(node->right){
                q.push({node->right, level+1});
            }
            if(node->left){
                q.push({node->left, level+1});
            }
        }

        for(auto p:nodes){
            ans.push_back(p.second);
        }

        return ans;
    }
*/
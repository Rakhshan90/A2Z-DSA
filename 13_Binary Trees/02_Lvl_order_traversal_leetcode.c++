/*
Problem statement: Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/

/*
Approach: Level order traversal using Queue

Initialize Queue and Result Vector:
1. Initialize an empty queue (q) to perform level-order traversal.
2. Initialize an empty vector of vectors (ans) to store the result.

Check for Empty Tree:
1. If the root is nullptr, return an empty vector (ans).

Level-Order Traversal:
1. Enqueue the root node into the queue.
2. While the queue is not empty:
   1. Get the current size of the queue (size).
   2. Initialize an empty vector (temp) to store the nodes at the current level.
   3. Loop through the nodes at the current level (based on the size of the queue):
      1. Dequeue the front node (frontNode) from the queue.
      2. Add the value of frontNode to the temp vector.
      3. Enqueue the left and right children of frontNode if they exist.
   4. Push the temp vector into the result vector (ans).

Return Result:
1. After the loop, return the 2D vector (ans) containing nodes at each level.

TC: O(n), SC: O(n)
*/

/*
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i<size; i++){
                TreeNode*frontNode = q.front();
                q.pop();
                temp.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
*/
/*
Problem statement: Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/

/*
Intuition: Considering the fact that we need to print the nodes, level by level, our first guess would definitely be that it must be related to level order traversal. If we closely examine, for even levels we need to go from left to right while for odd levels we need to go from right to left. 

Approach: The above idea, could be implemented with a queue. We initially keep an empty queue and push the root node. We also need to keep the left to right bool variable that keeps check of the current level we are in. As we traverse nodes in the queue, we need to push them in a temporary array. If left to right is false we need to reverse the array and push it in our data structure or else, simply push it in our data structure. In the end, when we have finished traversing the current level, we need to toggle our left to the right variable.
*/

/*
// Efficient solution 
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool flag = true;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode*node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!flag){
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
*/

/*
// Optimized solution
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool leftToRight = true;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            for(int i=0; i<size; i++){
                TreeNode*node = q.front();
                q.pop();
                int index = leftToRight ? i : size - 1 - i;
                temp[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
*/

//TC: O(N), SC: O(N)
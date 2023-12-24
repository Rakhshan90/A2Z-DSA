/*
Problem statement:
Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/

/*
Intuition: In preorder traversal, the tree is traversed in this way: root, left, right. When we visit a node, we print its value, and then we want to visit the left child followed by the right child.

Approach: Using stack [LIFO Order]
1. We first take an explicit stack data structure and push the root node to it.(if the root node is not NULL).
2. Then we use a while loop to iterate over the stack till the stack remains non-empty.
3. In every iteration we first pop the stack’s top and print it. 
4. Then we first push the right child of this popped node and then push the left child, if they are not NULL. We do so because stack is a last-in-first-out(LIFO) data structure. We need to access the left child first, so we need to push it at the last.
5. The execution continues and will stop when the stack becomes empty. In this process, we will get the preorder traversal of the tree.

TC: O(N), SC: O(N)
*/


/*
vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == nullptr) return ans;
        st.push(root);
        while(!st.empty()){
            TreeNode*node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
    }
*/
/*
Problem statment: Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/*
Intuition: In inorder traversal, the tree is traversed in this way: left, root, right. We first visit the left child, after returning from it we print the current node value, then we visit the right child. 

Approach: stack
1. We first take an explicit stack data structure and set an infinite loop.
2. In every iteration we check whether our current node is pointing to NULL or not.
3. If it is not pointing to null, we simply push the current value to the stack and move the current node to its left child.
4. If it is pointing to NULL, we first check whether the stack is empty or not. If the stack is empty, it means that we have traversed the tree and we break out of the loop.
5. If the stack is not empty, we pop the top value of the stack, print it and move the current node to its right child.

TC: O(n), SC: O(n)
*/

/*
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> st;
        TreeNode*node = root;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inOrder.push_back(node->val);
                node = node->right;
            }
        }
        return inOrder;
    }
*/
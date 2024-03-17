/*
Problem statement: Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/

/*
Approach: 
1. We will take index i, initialized with 0 to keep track over preorder array.
2. If the index i exceeds the size of the preorder array or the current value at preorder[i] is greater than bound,
node can not be insert at that position, so we will return nullptr.
3. Otherwise, create node at left of root node, then at right of root node.
4. whenever we call for function for left, we set a bound as root->val.
5. whenever we call for right, we set a bound as previous bound val.
6. return root.

TC: O(3N) -> O(N), SC: O(log N) 
*/

/*
TreeNode* solve(vector<int>& preorder, int &i, int bound){
        if(i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, i, root->val);
        root->right = solve(preorder, i, bound);
        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder, i, INT_MAX);
    }
*/
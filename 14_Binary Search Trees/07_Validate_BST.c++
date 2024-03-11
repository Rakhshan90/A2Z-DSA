/*
Problem statement: Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows: The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

/*
Approach: 
Base Case: If the current node (root) is nullptr, it's considered valid (an empty tree is a valid BST).

Check Node Value: If the current node's value (root->val) is less than the minimum allowed value (minVal) or greater than the maximum allowed value (maxVal), the tree is invalid.

Recursive Calls: The code recursively checks both the left and right subtrees:

For the left subtree, the minimum allowed value remains the same (minVal), but the maximum allowed value becomes the current node's value (root->val). This ensures that all elements in the left subtree are smaller than the current node.
For the right subtree, the minimum allowed value becomes the current node's value (root->val), and the maximum allowed value remains unchanged (maxVal). This ensures that all elements in the right subtree are greater than the current node.
Combining Results: The function returns true only if both the left and right subtrees are valid BSTs and the current node's value adheres to the BST property.

TC: O(n), SC: O(log n)
*/

/*
bool solve(TreeNode* root, long minVal, long maxVal){
        if(root == nullptr) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
*/
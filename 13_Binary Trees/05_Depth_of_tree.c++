/*
Problem statement: Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Input: root = [3,9,20,null,null,15,7]
Output: 3
*/

/*
Approach:
1. if current node is null return 0 as depth is 0 for null node.
2. we will get some answer from left subtree and also we will get some answer from right subtree.
3. choose max(leftAns, rightAns) and add 1 (which count for root node).
*/

/*
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0; 
        int leftAns = maxDepth(root->left);
        int rightAns = maxDepth(root->right);
        return max(leftAns, rightAns) + 1;
    }
*/

//TC: O(N), SC: O(H) Recursion Stack space, where “H”  is the height of the binary tree.
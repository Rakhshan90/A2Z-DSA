/*
Problem statement: You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
*/

/*
Approach: 
1. Set a while loop which runs till the time root is not NULL and root’s value is not equal to the target value we are searching for.
2. Inside the while loop, if the target value is less than the root’s value, move root to its left child, else move root to its right child.
3. When the while loop ends, return root as the answer.

TC: O(log n), SC: O(1)
*/

/*
TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr && root->val != val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
*/
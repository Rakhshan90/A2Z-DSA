/*
Problem statement: Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

/*
Approach: In a Binary Search Tree (BST), finding the Lowest Common Ancestor (LCA) involves traversing the tree from the root while comparing the values of the two nodes with the current node. At each step, if both nodes are smaller, move left; if larger, move right. When they diverge (one left, one right, or one is the current node), that node is the LCA.

Algorithm:
Step 1: Start at the root of the Binary Search Tree.

Step 2: Compare the values of the two nodes with the value of the current node.
If both nodes are smaller than the current node, they are both to its left hence move to its left child.
If both nodes are larger than the current node, they are both to its right hence move to its right child.
If one node is to the left and the other to the right of the current node, or if one node is the current node itself, then the current node is the LCA.

TC: O(H), SC: O(1)
*/

/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL)
            return NULL;
        if(root->val < p->val && root->val < q->val)
            //search in right side
            return lowestCommonAncestor(root->right, p, q);
        if(root->val > p->val && root->val > q->val)
            //search in left side
            return lowestCommonAncestor(root->left, p, q);
        //if came till here then return LCA
        return root;  //LCA found
    }
*/
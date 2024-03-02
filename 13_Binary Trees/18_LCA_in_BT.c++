/*
Problem statement: Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

/*
Approach: 
1. If root is null return null
2. If root is p or if root is q then return root
3. Made a recursion call for both
i) Left subtree 
ii)Right subtree
Because we would find LCA in the left or right subtree only.
4. If the left subtree recursive call gives a null value that means we haven’t found LCA in the left subtree, which means we found LCA on the right subtree. So we will return right.
5. If the right subtree recursive call gives null value, that means we haven’t found LCA on the right subtree, which means we found LCA on the left subtree. So we will return left .
6. If both left & right calls give values (not null)  that means the root is the LCA.

TC: O(N), SC: O(H)
*/

/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr) return right;
        else if(right == nullptr) return left;
        return root;
    }
*/
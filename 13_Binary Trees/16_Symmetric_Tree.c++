/*
Problem statement: Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

/*
Intuition: 
We need to understand the property of the mirror. We can ignore the root node as it is lying on the mirror line. In the next level, for a symmetric tree, the node at the root’s left should be equal to the node at the root’s right.
If we take two variables rootLeft and rootRight to represent the left child of root and right child of the root, then
Further, we need to understand that when rootLeft's value is equal to rootRight’s value, we need to further check for its children. As we are concerned about node positions through a mirror, rrootLeft’s left child should be checked with rootRight’s right child and rootLeft’s right child should be checked with rootRight’s left child. 

Approach: 
1. We take two variables rootLeft and rootRight initially both pointing to the root.
2. Then we use any tree traversal to traverse the nodes. We will simultaneously change rootLeft and rootRight in this traversal function.
3. For the base case, if both are pointing to NULL, we return true, whereas if only one points to NULL and other to a node, we return false.
4. If both points to a node, we first compare their value, if it is the same we check for the lower levels of the tree.
5. We recursively call the function to check the rootLeft’s left child with rootRight’s right child; then we again recursively check the rootLeft’s right child with rootRight’s left child.
6. When all three conditions ( node values of left and right and two recursive calls) return true, we return true from our function else we return false.

TC: O(N), SC: O(N)
*/

/*
bool solve(TreeNode*leftRoot, TreeNode*rightRoot){
        if(!leftRoot && !rightRoot) return true;
        if(!leftRoot || !rightRoot) return false;
        if(leftRoot->val != rightRoot->val) return false;
        return solve(leftRoot->left, rightRoot->right) && 
        solve(leftRoot->right, rightRoot->left);
    }
    bool isSymmetric(TreeNode* root) {
        return !root || solve(root->left, root->right);
    }
*/
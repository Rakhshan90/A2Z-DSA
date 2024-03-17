/*
Problem statement: You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
*/

/*
Approach 2: Optimized approach
Property of BST says, inorder traversal of BST is always sorted.
1. Perform the inorder traversal on the given BST.
2. When you visit a node, if current node's value is less than previous node's value, then there is violation against
BST property. if there is first violation, then store the previous node as first violation, and current node as 
mid violation.
3. If there is second violation, then store the current node as last violation.
4. If first and last violation found, then swap there values.
5. else if first and mid violation found, then swap there values.

TC: O(n), SC: O(1) if we are not considering recursive stack space.
*/

/*
class Solution {
private:
TreeNode* first;
TreeNode* prev;
TreeNode* mid;
TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev != nullptr && (root->val < prev->val)){
            // if this is a first violation, mark these two nodes as
            // first and mid
            if(first == nullptr){
                first = prev;
                mid = root;
            }
            // if this is second violation, mark this node as last
            else last = root;
        }
        // mark this node as previous
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = last = prev = mid = nullptr;
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && mid) swap(first->val, mid->val);
    }
};
*/
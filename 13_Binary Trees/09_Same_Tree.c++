/*
Problem statement: Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

/*
bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both nodes are null, they are equal
        if(p == nullptr && q == nullptr) return true;

        // If one of the nodes is null while the other is not, they are not equal
        if(p == nullptr || q == nullptr) return false;

        //if values of both nodes are not equal, they are not same
        if(p->val != q->val) return false;

        // Recursively check the left and right subtrees
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        // Return true only if both left and right subtrees are equal
        return left && right;
    }
*/

// TC: O(n), SC: O(h)
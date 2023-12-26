/*
Problem statement: Given a binary tree, determine if it is height-balanced. A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

/*
Approach 1: Naive approach
For a Balanced Binary Tree, Check left subtree height and right subtree height for every node present in the tree. Hence, traverse the tree recursively and calculate the height of left and right subtree from every node, and whenever the condition of Balanced tree violates, simply return false.

TC: O(N*N) ( For every node, Height Function is called which takes O(N) Time. Hence for every node it becomes N*N ) 
SC: O(H)
*/

/*
int height(TreeNode*root){
        if(root == nullptr) return 0;
        int leftAns = height(root->left);
        int rightAns = height(root->right);
        return max(leftAns, rightAns) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int diff = abs(height(root->left) - height(root->right));
        if(diff > 1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right) return false;
        return true; 
    }
*/

/* 
Solution 2: Using Post Order Traversal [Optimized]
Intution: The idea is to use post-order traversal. Since, in postorder traversal, we first traverse the left and right subtrees and then visit the parent node, similarly instead of calculating the height of the left subtree and right subtree every time at the root node, use post-order traversal, and keep calculating the heights of the left and right subtrees and perform the validation.

Approach 2: 
1. Start traversing the tree recursively and do work in Post Order.
2. For each call, caculate the height of the root node, and return it to previous calls.  
3. Simultaneously, in the Post Order of every node , Check for condition of balance as information of left and right subtree height is available.
4. If it is balanced , simply return height of current node and if not then return -1.
5. Whenever the subtree result is -1 , simply keep on returning -1.
*/

/*
int height(TreeNode*root){
        if(root == nullptr) return 0;

        int left = height(root->left);
        if(left == -1) return -1;

        int right = height(root->right);
        if(right == -1) return -1;

        int diff = abs(left - right);
        if(diff > 1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
*/
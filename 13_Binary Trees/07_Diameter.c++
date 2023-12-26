/*
Problem statement: Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
*/

/*
Intuition: So, the idea to find the Curving Point is, consider every node in the tree as a curving point and calculate the diameter for every curving point and return the maximum of all diameters.
Diameter at given Curving Point = Left Height + Right Height 

Approach: 
1. Traverse the tree recursively.
2. At every node, calculate height of left and right subtrees.
3. Calculate the diameter for every node using the above formula.
4. Calculate the maximum of all diameters. This can be done simply using a variable passed by reference in the recursive calls or a global static variable.

TC: O(n), SC: O(h)
*/

/*
    int height(TreeNode*root, int &diameter){
        if(root == nullptr) return 0;

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        height(root, diameter);
        return diameter;
    }
*/
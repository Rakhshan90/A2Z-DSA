/*
Problem statement: Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example: 
Input: inOrder = [40, 20, 50, 10, 60, 30], preOrder = [10, 20, 40, 50, 30, 60]
Output: [10, 20, 30, 40, 50, 60, null]
*/

/*
Approach: Recursive Tree Construction:

1. The base case checks if the indices are invalid (preStart > preEnd or inStart > inEnd). If true, return nullptr.
2. Create a new TreeNode with the value at the current preStart index in the preorder vector.
3. Find the index of the current node's value in the inorder vector using the inMap.
4. Calculate the number of nodes in the left subtree (numsLeft) by subtracting inStart from the index.
5. Recursively construct the left subtree using the appropriate indices in both preorder and inorder.
6. Recursively construct the right subtree using the appropriate indices in both preorder and inorder.
7. Return the root of the subtree.
*/

/*
TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, 
    vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap){

        if((preStart > preEnd) || (inStart > inEnd)) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = inMap[root->val];
        int numsLeft = index - inStart;
        root->left = solve(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, index - 1, inMap);
        root->right = solve(preorder, preStart + numsLeft + 1, preEnd, inorder, index + 1, inEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder, 0, n-1, inorder, 0, m-1, inMap);
        return root;
    }
*/
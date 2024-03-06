/*
Problem statement: Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/

/*
Approach: Recursive Tree Construction:

1. The base case checks if the indices are invalid (postStart > postEnd or inStart > inEnd). If true, return nullptr.
2. Create a new TreeNode with the value at the current postEnd index in the postorder vector.
3. Find the index of the current node's value in the inorder vector using the inMap.
4. Calculate the number of nodes in the left subtree (numsLeft) by subtracting inStart from the index.
5. Recursively construct the left subtree using the appropriate indices in both postorder and inorder.
6. Recursively construct the right subtree using the appropriate indices in both postorder and inorder.
7. Return the root of the subtree.

TC: O(N), SC: O(N)
*/

/*
TreeNode* solve(vector<int>& postorder, int postStart, int postEnd, 
    vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap){

        if((postStart > postEnd) || (inStart > inEnd)) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int index = inMap[root->val];
        int numsLeft = index - inStart;
        root->left = solve(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, index - 1, inMap);
        root->right = solve(postorder, postStart + numsLeft, postEnd - 1, inorder, index + 1, inEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int m = inorder.size();
        map<int, int> inMap;
        for(int i=0; i<m; i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = solve(postorder, 0, n-1, inorder, 0, m-1, inMap);
        return root;
    }
*/
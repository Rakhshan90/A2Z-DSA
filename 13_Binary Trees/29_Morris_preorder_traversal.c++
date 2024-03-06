/*
Problem statement: Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/

/*
Approach: 
When we are currently at a node, the following cases can arise:
Case 1: When the current node has no left subtree. In this scenario, there is nothing to be traversed on the left side, so we simply print the value of the current node and move to the right of the current node.
Case 2: When there is a left subtree and the right-most child of this left subtree is pointing to null. In this case we need to set the right-most child to point to the current node, instead of NULL, print the current node value and move to the left of the current node.
Case 3: When there is a left subtree and the right-most child of this left-subtree is already pointing to the current node. In this case we know that the left subtree is already visited so we need to reset the last node to NULL and move the current node to its right. 
Note: Case 3 is very important as we need to remove the new links added to restore the original tree. 

TC: O(N), SC: O(1)
*/

/*
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                preorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode*pre = curr->left;
                while(pre->right != nullptr && pre->right != curr){
                    pre = pre->right;
                }
                if(pre->right == nullptr){
                    //creating thread
                    pre->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    //pre->right = curr
                    //removing thread
                    pre->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
*/
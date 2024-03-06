/*
Problem statment: Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/*
Approach: Morris inorder traversal
When we are currently at a node, the following cases can arise:
Case 1: When the current node has no left subtree. In this scenario, there is nothing to be traversed on the left side, so we simply print the value of the current node and move to the right of the current node.
Case 2: When there is a left subtree and the right-most child of this left subtree is pointing to null. In this case we need to set the right-most child to point to the current node, instead of NULL and move to the left of the current node.
Case 3: When there is a left subtree and the right-most child of this left-subtree is already pointing to the current node. In this case we know that the left subtree is already visited so we need to print the value of the current node and move to the right of the current node.
Note: Case 3 is very important as we need to remove the new links added to restore the original tree. 

TC: O(N), SC: O(1)
*/

/*
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode*curr = root;
        while(curr != nullptr){
            if(!curr->left){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode*pre = curr->left;
                while(pre->right != nullptr && pre->right != curr){
                    pre = pre->right;
                }
                if(pre->right == nullptr){
                    //creating thread
                    pre->right = curr;
                    curr = curr->left;
                }
                else{
                    //pre->right = curr
                    //removing thread
                    pre->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
*/
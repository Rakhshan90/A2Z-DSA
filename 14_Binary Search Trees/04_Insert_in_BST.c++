/*
Problem statement: You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/

/*
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode*curr = root;
        while(true){
            if(curr->val < val){
                if(curr->right != nullptr) curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left != nullptr) curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
*/

/*
TC: O(log n), SC: O(1)
*/
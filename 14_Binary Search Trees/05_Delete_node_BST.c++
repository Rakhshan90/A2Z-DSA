/*
Problem statement: Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
*/

/*
Approach: 
Step 1: Search for the node to delete:
Start from the root and if the key is less than the current node, move to the left subtree and if the key is greater than the current node, move to the right subtree. Repeat this until we find the node to delete or reach a null node.

Step 2: Handle Different Cases for Deletion:
Case 1: If the node has no children (leaf nodes), simply remove the node.
Case 2: If the node has one child, replace the node to be deleted with its child.
Case 3: If the node has two children,
Find the node’s inorder predecessor by traversing the left subtree of the node to find the rightmost (largest) node. Store this as lastRight.
Set the right child lastRight’s to the node to be deleted.
Skip over the node to be deleted by directly connecting the root to the node’s left child ie. the root of the left subtree.

Step 3: Return the modified Binary Search Tree.

TC: O(log n), which is height of the BST, SC: O(1)
*/

/*
TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        TreeNode* dummy = root;
        if(root->val == key) return helper(root);
        while(root){
            if(root->val >= key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else root = root->right;
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
*/
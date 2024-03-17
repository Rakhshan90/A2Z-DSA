/*
Problem statement: You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.
Your task is to return the predecessor and successor of the given node in the BST.
Note:
1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.
2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.
3. The node for which predecessor and successor are to be found will always be present in the given tree. 

Sample Input 1:
15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
10
Sample output 1:
8 12
*/

/*
Approach: Optimized approach

findPredecessor Function:
Initialize a pointer pre to NULL.
Traverse the BST from the root node:
If the current node's value is greater than or equal to the key, move to its left child.
Otherwise, update pre to the current node and move to its right child.
Return the pointer pre, which points to the predecessor node of the given key.

findSuccessor Function:
Initialize a pointer succ to NULL.
Traverse the BST from the root node:
If the current node's value is less than or equal to the key, move to its right child.
Otherwise, update succ to the current node and move to its left child.
Return the pointer succ, which points to the successor node of the given key.

TC: O(log n), SC: O(1)
*/

/*
TreeNode *findPredecessor(TreeNode *root, int key){
    TreeNode *pre = NULL;
    while(root != NULL){
        if(root->data >= key) root = root->left;
        else{
            pre = root;
            root = root->right;
        }
    }
    return pre;
}
TreeNode *findSuccessor(TreeNode *root, int key){
    TreeNode *succ = NULL;
    while(root != NULL){
        if(root->data <= key) root = root->right;
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *pre = findPredecessor(root, key);
    TreeNode *succ = findSuccessor(root, key);
    if(pre != NULL && succ == NULL) return {pre->data, -1};
    else if(pre == NULL && succ != NULL) return {-1, succ->data};
    else if(pre == NULL && succ == NULL) return {-1, -1};
    else return {pre->data, succ->data};
}
*/
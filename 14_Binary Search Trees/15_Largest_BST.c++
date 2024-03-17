/*
Problem statement: You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to return the size of the largest subtree of the binary tree which is also a BST.
*/

/*
Approach 1: Brute force
1. For every node we check if this is a valid BST using range approach.
2. Once we got the valid BST, we will pass its root node to the countNodes function to calculate total number of nodes from root node till leaf nodes.
3. we will repeat this process until every nodes in BT is validated for BST, hence we will return largest size of the BST.

TC: O(N * N), where N for traversing each node, and another N for valdating each node for BST
*/

/*
Approach 2: By using concept of Post order traversal(Left, Right, Root) Optimized approach

nodeVal Structure: This structure holds three values for each subtree:
minVal: Minimum value allowed in the subtree (ensures BST property).
maxVal: Maximum value allowed in the subtree (ensures BST property).
maxSize: Size of the largest BST subtree found within the current subtree.

findLargestBST Function: This recursive function takes a TreeNode as input and returns a nodeVal.
Base Case: If the current node (root) is null, it represents an empty subtree and returns a nodeVal with minVal set to infinity (INT_MAX), maxVal set to negative infinity (INT_MIN), and maxSize set to 0 (no valid BST in an empty subtree).
Recursive Calls: It calls itself on the left and right subtrees, storing the returned nodeVal objects in left and right.
Validity Check: It checks if the current node's value (root->data) adheres to the BST property: larger than the maximum allowed value in the left subtree (left.maxVal) and smaller than the minimum allowed value in the right subtree (right.minVal).
Valid BST: If the condition holds, it signifies a valid BST subtree. The function then returns a new nodeVal with:
minVal: The minimum of the current node's value and the minimum allowed value in the left subtree (left.minVal). This ensures the BST property continues in the larger subtree.
maxVal: The maximum of the current node's value and the maximum allowed value in the right subtree (right.maxVal). This ensures the BST property continues in the larger subtree.
maxSize: The sum of the sizes of the largest BST subtrees in the left and right subtrees (left.maxSize + right.maxSize) plus 1 (accounting for the current node).
Invalid BST: If the condition fails, it signifies a violation of the BST property. The function returns a nodeVal with minVal and maxVal set to invalid values (INT_MIN and INT_MAX) and maxSize set to the maximum size of the largest BST subtrees found in the left and right subtrees (max(left.maxSize, right.maxSize)). This indicates that the current subtree is not a valid BST.

TC: O(N), SC: O(1) if we don't consider recursive stack space.
*/

/*
class nodeVal{
    public: 
    int minVal, maxVal, maxSize;
    nodeVal(int minVal, int maxVal, int maxSize){
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};
nodeVal findLargestBST(TreeNode *root){
    if(!root) return nodeVal(INT_MAX, INT_MIN, 0);
    auto left = findLargestBST(root->left);
    auto right = findLargestBST(root->right);

    if((root->data > left.maxVal) &&( root->data < right.minVal)){
        // valid bst
        return nodeVal(min(root->data, left.minVal), max(root->data, right.maxVal), left.maxSize + 
        right.maxSize + 1);
    }
    return nodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(TreeNode *root){
    return findLargestBST(root).maxSize;
}
*/
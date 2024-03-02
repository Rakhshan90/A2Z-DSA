/*
Problem statment: Return true if all non-leaf nodes in a given binary tree have a value that is equal
to the sum of their child nodes, otherwise return false.
*/

/*
Approach: Recursive DFS Traversal:
1. Base case: If the current node is null or is a leaf node (has no left and right children), return.
2. Calculate the sum of the values of the left and right child nodes (if they exist).
3. If the sum is equal to the value of the current node, recursively call solve on the left and right children.
4. If the sum is not equal to the value of the current node, set ans to false.

TC: O(N), SC: O(H)
*/

/*
void solve(Node*root, bool &ans){
    //base case
    if((!root) || (!root->left && !root->right)) return;

    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(sum == root->data){
        solve(root->left, ans);
        solve(root->right, ans);
    }
    else ans = false;

}
bool isParentSum(Node *root){
    bool ans = true;
    solve(root, ans);
    return ans;
}
*/


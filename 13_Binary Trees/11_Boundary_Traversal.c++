/*
Problem statement: You are given a binary tree having 'n' nodes. The boundary nodes of a binary tree include the nodes from the left and right
boundaries and the leaf nodes, each node considered once.
Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.
*/

/*
Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

Part 1: Left Boundary of the tree (excluding the leaf nodes).
Part 2: All the leaf nodes travelled in the left to right direction.
Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.
We take a simple data structure like a vector/Arraylist to store the Boundary Traversal. The root node is coming from both the boundaries (left and right). Therefore, to avoid any confusion, we push it on our list at the very start.

TC: O(N), SC: O(N)
*/

/*
bool isLeaf(TreeNode<int> *root){
    if(!root->left && !root->right) return true;
    else return false;
}
void leftBoundary(TreeNode<int> *root, vector<int> &ans){
    TreeNode<int> *curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void rightBoundary(TreeNode<int> *root, vector<int> &ans){
    TreeNode<int> *curr = root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=temp.size() - 1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}
void leafNodes(TreeNode<int> *root, vector<int> &ans){
    if(isLeaf(root)) ans.push_back(root->data);
    if(root->left) leafNodes(root->left, ans);
    if(root->right) leafNodes(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftBoundary(root, ans);
    leafNodes(root, ans);
    rightBoundary(root, ans);
    return ans;


}
*/
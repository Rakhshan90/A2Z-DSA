/*
Problem statment: Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.
*/

/*
Approach : Recursive Path Generation

1. The solve function is a recursive function that generates paths from the current node to each leaf node.
2. If the current node is a leaf node (both left and right children are null), append the value of the leaf node to the current path and add the path to the output vector.
3. If the current node is not a leaf node, append the value of the current node to the current path, add "->" to the path, and recursively call solve for both the left and right children.
4. After the recursive calls, pop the last two characters from the path to backtrack.

TC: O(N), SC O(H)
*/

/*
void solve(TreeNode* root, vector<string> &output, string path){
        if(root->left == nullptr && root->right == nullptr){
            path += to_string(root->val);
            //leaf node, add current path into output
            output.push_back(path);
            path.pop_back();
            return;
        }
        path += to_string(root->val);
        path += "->";
        if(root->left != nullptr) solve(root->left, output, path);
        if(root->right != nullptr) solve(root->right, output, path);
        path.pop_back();
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        if(root == nullptr) return output;
        string path;
        solve(root, output, path);
        return output;
    }
*/
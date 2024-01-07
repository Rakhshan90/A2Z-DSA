/*
Problem statement: A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

/*
Intuition: So, the idea to find the Curving Point is, consider every node in the tree as a curving point and calculate the max path sum for every curving point and return the maximum path sum of all paths.
maximum path sum at given Curving Point = leftPathSum + rightPathSum + NodeValue(curving point)

Approach: using maxHeight of binary tree approach (Optimized)
1. Traverse the tree recursively.
2. At every node, calculate leftPathSum and rightPathSum.
3. Calculate the maxPathSum for every node using the above formula.
4. if at any point, we get negative value either from left or right, take it as zero.

TC: O(N), SC: O(N)
Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
*/

/*
int maxPathDown(TreeNode*root, int &maxSum){
        if(root == nullptr) return 0;
        int left = max(0, maxPathDown(root->left, maxSum));
        int right = max(0, maxPathDown(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathDown(root, maxSum);
        return maxSum;
    }
*/
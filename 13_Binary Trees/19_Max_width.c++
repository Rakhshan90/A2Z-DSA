/*
Problem statement: Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

/*
BFS Traversal with Indexing:
1. Perform a level-order traversal of the binary tree using a queue (q).
2. Assign unique indices to each node in the tree based on its position in the level-order traversal.
3. Keep track of the first and last indices encountered at each level.
Width Calculation:
1. Calculate the width at each level by finding the difference between the last and first indices of the nodes at that level.
2. Update the overall maximum width if the calculated width at the current level is greater than the current maximum.

TC: O(N), SC: O(H)
*/

/*
int widthOfBinaryTree(TreeNode* root) {
        long long width = 0;
        if(!root) return width;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            long long minIndex = q.front().second;
            long long first, last;
            for(int i=0; i<size; i++){
                long long currIndex = q.front().second - minIndex;
                TreeNode*node = q.front().first;
                q.pop();
                if(i==0) first = currIndex;
                if(i==size-1) last = currIndex;
                if(node->left) q.push({node->left, 2*currIndex+1});
                if(node->right) q.push({node->right, 2*currIndex+2});
            }
            width = max(width, last - first + 1);
        }
        return width;
    }
*/
/*
Problem statement: Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
*/

/*
Intuition: First of all, we need to assign a vertical and a level to every node. Once we assign them, we need to figure out a suitable data structure to store them. This data structure should give us the nodes with left-side vertical first and in every vertical, top-level node should appear first. There can be a case that two or more nodes overlap at the same vertical and level. In such a case we will print nodes with lesser value first. Therefore for every level, we need a data-structure which can store node values in a sorted order. Moreover, as duplicate values are allowed in our tree, our data structure needs to handle this well. This is acheived by using multiset in C++. Multiset is similar to a set which keeps elements in sorted order but also allows duplicates. 

Approach: 

We will perform a tree traversal and assign a vertical and level to every node. Based on this vertical and node, we store the node in our special data structure. For easy understanding, we break it into these steps:

Step-1: Assigning vertical and level to every node using level order traversal.
queue<node*, vertical, level>

Step-2: Storing Verticals and levels to our data structure
map<vertical, map<level, multiset<int>>>

Step 3: Printing vertical order traversal from our data structure

TC: O(N * log(K)), SC: O(N)
*/

/*
vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        // Step 1:
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int v = node.second.first;
            int l = node.second.second;
            // Step 2: 
            nodes[v][l].insert(node.first->val);
            if(node.first->left){
                q.push({node.first->left, {v-1, l+1}});
            }
            if(node.first->right){
                q.push({node.first->right, {v+1, l+1}});
            }
        }
        
        // Step 3:
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
*/
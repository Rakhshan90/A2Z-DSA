/*
Problem statement: Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.
*/

/*
Intuition: We have to consider each vertical from left to right. we only consider the last bottom node for each vertical.

Approach: 
Same approach as we used in top view, but the only change here is that we don't need to check if key(vertical) is exist or not. because if key(vertical) is exist, then we need to update the new node corresponding the key(vertical), if key(vertical) is not exists, then we need to add node corresponding the key(vertical).

TC: O(N), SC: O(N)
*/

/*
vector <int> bottomView(Node *root) {
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, int> nodes;
        q.push({root, 0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int v = node.second;
            nodes[v] = node.first->data;
            if(node.first->left){
                q.push({node.first->left, v-1});
            }
            if(node.first->right){
                q.push({node.first->right, v+1});
            }
        }
        
        for(auto p:nodes){
            ans.push_back(p.second);
        }
        return ans;
    }
*/
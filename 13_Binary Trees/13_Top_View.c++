/*
Problem statement: Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Note: Return nodes from leftmost node to rightmost node.
*/

/*
Intuition: We have to consider each vertical from left to right. we only consider the first top node for each vertical.

Approach: 
1. First we have to make a queue of pair which have nodes and their respective +vertical and -vertical indexes.
2. Then we need a map data structure to store the vertical and the nodes. This map will store the data in the form of sorted orders of keys(vertical).
3. Here we will follow the level order traversal.
4. Traverse through the nodes starting with root,0 and store them to the queue.
5. Until the queue is not empty, store the node  and vertical no. in 2 separate variable .
6. Then check if that line is present in the map or not
7. If not present then store the line and the node->val to the map
8. Otherwise store the node->left and node->right along with there vertical nos. to the queue.
9. Then print the node->val from the map

TC: O(n), SC: O(n)
*/

/*
vector<int> topView(Node *root)
    {
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, int> nodes;
        q.push({root, 0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int v = node.second;
            if(nodes.find(v) == nodes.end()){
                nodes[v] = node.first->data;
            }
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
/*
Problem statement: Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
*/

/*
Approach: 
Serialization (serialize function):
Initialize an empty string s to store the serialized representation.
Use a queue (q) to perform level-order traversal.
Enqueue the root of the tree (q.push(root)).
While the queue is not empty:
Dequeue a node (current) from the queue.
If current is nullptr, append "#," to the string s.
If current is not nullptr:
Append the value of the current node to the string s followed by a comma (to_string(current->val) + ",").
Enqueue the left and right children of the current node (q.push(current->left) and q.push(current->right)).
Return the serialized string s.

Deserialization (deserialize function):
If the input string data is empty, return nullptr (empty tree).
Use a stringstream s to tokenize the input string.
Read the first token from the stringstream (getline(s, str, ',')) to get the value of the root.
Create the root node using the parsed value.
Use a queue (q) to perform level-order traversal.
Enqueue the root node into the queue (q.push(root)).
While the queue is not empty:
Dequeue a node (current) from the queue.
Read the next token from the stringstream (getline(s, str, ',')).
If str is "#", set the left child of current to nullptr.
If str is not "#", create a new node with the parsed value and set it as the left child of current. Enqueue the new node (q.push(leftNode)).
Repeat steps 5-8 for the right child of current.
Return the root of the deserialized tree.

TC: O(N), SC: O(N)
*/


/*
// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        while(!q.empty()){
            TreeNode*current = q.front();
            q.pop();
            if(current == nullptr) s.append("#,");
            else s.append(to_string(current->val) + ",");
            if(current != nullptr){
                q.push(current->left);
                q.push(current->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode*root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode*current = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#"){
                current->left = nullptr;
            }
            else{
                TreeNode*leftNode = new TreeNode(stoi(str));
                current->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if(str == "#") current->right = nullptr;
            else{
                TreeNode*rightNode = new TreeNode(stoi(str));
                current->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
*/
/*
Problem statement: Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/

/*
Solution 1: In-order traversal 
Find the in-order traversal of BST and store it in a container. You don't need to sort the container because the in-order of BST will always be sorted. return inOrder[k-1] as the kth smallest element.

TC: O(N), SC: O(N)
*/

/*
void solve(TreeNode* root, vector<int> &inOrder){
        if(!root) return;
        solve(root->left, inOrder);
        inOrder.push_back(root->val);
        solve(root->right, inOrder);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        vector<int> inOrder;
        solve(root, inOrder);
        return inOrder[k-1];
    }
*/

/*
Solution 2: Morris in-order traversal (Optimized solution)
The Morris Traversal technique uses threads to traverse the tree without using additional space. In this particular problem, the code leverages Morris Traversal to efficiently find the kth smallest element in the BST without using recursion or a stack.
The variable cnt keeps track of the number of nodes visited during the traversal.
The variable ans holds the value of the kth smallest element found so far.

Perform morris in-order traversal to visit nodes and increment cnt.
If cnt is equal to k, update ans with the value of the current node.
When curr becomes nullptr, Return the value of ans, which holds the kth smallest element.

TC: O(N), SC: O(1)
*/

/*
int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int cnt = 0;
        int ans;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(!curr->left){
                cnt++;
                if(cnt == k){
                    ans = curr->val;
                }
                curr = curr->right;
            }
            else{
                TreeNode *pre = curr->left;
                while(pre->right != nullptr && pre->right != curr){
                    pre = pre->right;
                }
                if(pre->right == nullptr){
                    //creating thread
                    pre->right = curr;
                    curr = curr->left;
                }
                else{
                    //removing thread
                    pre->right = nullptr;
                    cnt++;
                    if(cnt == k){
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
*/
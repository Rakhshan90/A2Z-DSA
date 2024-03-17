/*
Problem statement: Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/

/*
Approach 1: Efficient approach
1. Find inorder of the given BST.
2. As we know inorder of BST will always be sorted, so perform two pointer approach.
3. Find sum by calculating inorder[start] + inorder[end]. 
3. if sum is == k, then return true
4. if sum is > k, decrement j--
5. else increment i++
6. if no two elements exist in the BST whose sum is equal to k, return false.

TC: O(n), SC: O(n)
*/

/*
void inOrder(TreeNode* root, vector<int>&in){
        //base case
        if(root==NULL)
            return;
        inOrder(root->left, in);
        in.push_back(root->val);
        inOrder(root->right, in);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>in;
        inOrder(root, in);
        int size = in.size();
        int i =0;
        int j = size-1;
        while(i<j){
            int sum = in[i]+in[j];
            if(sum==k)
                return true;
            else if(sum>k)
                j--;
            else
                i++;
        }
        return false;
    }
*/

/*
Approach 2: By using concept of "BST Iterator" [Optimized approach]
Intuition: As we know, next process provides values in ascending order. We also need its descending order values, so we will find the reverse of next process and that will be called as before.
We will use same class BSTIterator to achieve both next and before process. Once we got values in both ascending and descending order, we will mark two pointers i, and j on next and before respectively. Then we will simply compare
if i + j == k, return true, else if i + j < k, we need bigger sum so we have to move in ascending order, so increment i, else we need smaller sum so we have to move in descending order, so increment j.

TC: O(N), SC: O(H)
*/

/*
class BSTIterator {
private: 
    stack<TreeNode*> myStack;
    //reverse = false -> next
    //reverse = true -> before
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* top = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(top->right);
        else pushAll(top->left);
        return top->val;
    }
    
    private:
    void pushAll(TreeNode* root){
        while(root != nullptr){
            myStack.push(root);
            if(!reverse) root = root->left;
            else root = root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false); // next
        BSTIterator r(root, true); // before
        int i=l.next();
        int j=r.next(); //r.before
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
*/
/*
Problem statement: Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
*/

/*
Approach: Logic of algorithm borrowed from inorder traversal approach
Algorithm:
1. Pass root node to the constructor "BSTIterator".
2. Push all the nodes from root node to the left most node in the stack.
3. stack's top represents the left most node, so whenever we got next call then return stack's top value.
4. If right of top node of stack is exists, then again push all the nodes from top's right node to the leftmost node 
into the stack. 
5. Wehenever we got hasNext call, we will return true if stack is not empty otherwise return false.

TC: O(1) of both the functions next(), hasNext(), SC: O(H)
*/

/*
class BSTIterator {
private: stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* top = myStack.top();
        myStack.pop();
        if(top->right) pushAll(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
    private:
    void pushAll(TreeNode* root){
        while(root != nullptr){
            myStack.push(root);
            root = root->left;
        }
    }
};
*/
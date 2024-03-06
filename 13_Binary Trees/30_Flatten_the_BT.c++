/*
Problem statement: Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

/*
Solution 3 – Using Intuition behind Morris Traversal (Optimized solution)

Intuition: We will use the intuition behind morris’s traversal. In Morris Traversal we use the concept of a threaded binary tree.

Approach:
The algorithm can be described as:
At a node(say cur) if there is not left child, we simply move to the right of cur.
At a node(say cur) if there exists a left child, we will find the rightmost node in the left subtree(say prev).
We will set prev’s right child to cur’s right child,
We will then set cur’s right child to it’s left child.
We will then move cur to the next node by assigning cur it to its right child
We will stop the execution when cur points to NULL.

TC: O(N), SC: O(1)
*/

/*
void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != nullptr){
            if(!curr->left){
                curr = curr->right;
            }else{
                TreeNode* pre = curr->left;
                while(pre->right != nullptr){
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
                curr = curr->right;
            }
        }
    }
*/
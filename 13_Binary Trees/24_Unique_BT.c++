/*
Problem statement: Problem statement
Given a pair of tree traversal, return 'true' if a unique binary tree can be constructed otherwise 'false'.

Note:
Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.   

Example:
For 'a' = 2, ‘b’ = 3.
Answer is True.

Example:
For 'a' = 2, ‘b’ = 2.
Answer is false.
*/

/*
Solution: inOrder is must to create a unique binary tree. Combination of (inOrder and postOrder) or 
(inOrder and preOrder) will provide us a unique binary tree. other than that no unique binary tree can be made.
*/

/*
int uniqueBinaryTree(int a, int b){
    if((a == 1 && b == 1) || (a == 2 && b == 2) || (a == 3 && b == 3) ||
    (a == 1 && b == 3) || (a == 3 && b == 1)) return false;
    else return true;
}
*/
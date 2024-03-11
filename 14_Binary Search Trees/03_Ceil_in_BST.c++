/*
Problem statement: Ceil of an integer is the closest integer greater than or equal to a given number.
For example:
arr[] = {1, 2, 5, 7, 8, 9}, key = 3.
The closest integer greater than 3 in the given array is 5. So, its ceil value in the given array is 5.
*/

/*
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    while(node != nullptr){
        if(node->data >= x){
            ans = node->data;
            node = node->left;
        }
        else node = node->right;
    }
    return ans;
}
*/
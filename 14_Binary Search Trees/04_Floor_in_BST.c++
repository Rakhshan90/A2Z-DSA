/*
Problem statement: Given a binary search tree and an integer.Find the floor value of a key in a binary search tree .

(If k lies in BST then is floor equal to k,else floor is equal to previous greater value) Note: k would never be less than the minimum element of tree.

Sample Input 1:
4
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2
*/

/*
int Floor(BinaryTreeNode<int> *node, int input)
{
	int ans = -1;
    while(node != nullptr){
		if(node->data == input){
			ans = node->data;
			return ans;
		}
        if(node->data < input){
			ans = node->data;
            node = node->right;
        }
        else node = node->left;
    }
    return ans;
}
*/
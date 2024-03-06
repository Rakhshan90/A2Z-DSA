/*
Problem statment: Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.
*/

/*
Solution 1: Any traversal(inOrder, preOrder, postOrder)
1. Perfrom any traversal to visit each node in the comple binary tree.
2. Every time you you visit a node, increment count by 1.
3. return cnt of nodes.

TC: O(N), SC: O(H)
*/

/*
void solve(TreeNode*root, int &cnt){
        if(!root) return;
        solve(root->left, cnt);
        cnt++;
        solve(root->right, cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
*/

/*
Solution 2: Property of complete binary tree(Efficient solution)
1. Set a recursive function to calculate the number of nodes.
2. In the recursive function, calculate leftHeight and the right Height of the tree from the given node.
3. If leftHeight == rightHeight, return 2leftHeight – 1.
4. If leftHeight != rightHeight, recursively call the function to calculate nodes in left subtree(leftNodes) and the right subtree(rightNodes) and return 1+leftNodes+rightNodes.

TC: O(log^2 N), SC: O(log N) or O(H)
*/

/*
int leftHeight(TreeNode*root){   
        int cnt = 0;
        while(root){
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int rightHeight(TreeNode*root){
        int cnt = 0;
        while(root){
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {      //O(log n)
        if(!root) return 0;
        int lh = leftHeight(root);        //O(log n)
        int rh = rightHeight(root);       //O(log n)
        if(lh == rh) return (1<<lh) - 1;  
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
*/
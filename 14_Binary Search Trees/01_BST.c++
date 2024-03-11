#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// BST build by via recursion
Node *insertInBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // insert in right side
        root->right = insertInBST(root->right, d);
    }
    else
    {
        // insert in left side
        root->left = insertInBST(root->left, d);
    }
    return root;
}
void input(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
}

Node *minNode(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxNode(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
//recursive
// void findPreSuc(Node *root, int key, Node *&pre, Node *&suc)
// {
//     // base case
//     if (root == NULL)
//         return;
//     // if key is found then find pre and suc
//     if (root->data == key)
//     {
//         if (root->left != NULL)
//         {
//             pre = root->left;
//             while (pre->right != NULL)
//             {
//                 pre = pre->right;
//             }
//         }
//         if(root->right!=NULL){
//             suc = root->right;
//             while(suc->left!=NULL){
//                 suc = suc->left;
//             }
//         }
//         return;
//     }
//     if(root->data > key){
//         //set the successor as root
//         //search recursively into left subtree
//         suc = root;
//         findPreSuc(root->left, key, pre, suc);
//     }
//     else{
//         //set the predecessor as root
//         //search recursively into right subtree
//         pre = root;
//         findPreSuc(root->right, key, pre, suc);
//     }
// }

//iterative
void findPreSuc(Node *root, int key, Node *&pre, Node *&suc){
    Node*temp1 = root;
    // temp1 will give successor 
    while(temp1){
        if(temp1->data > key){
            suc = temp1;
            temp1 = temp1->left;
        }
        else 
           temp1 = temp1->right;
    }
    Node*temp2 = root;
    //temp2 will give predecessor
    while(temp2){
        if(temp2->data<key){
            pre = temp2;
            temp2 = temp2->right;
        }
        else 
           temp2 = temp2->left;
    }
    return;
}

// iterative way
Node *levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // Previous level traverse ho chuka
        if (temp == NULL)
        {
            cout << endl; // enter
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // if temp->left isn't NULL
            if (temp->left)
            {
                q.push(temp->left);
            }
            // if temp->right isn't NULL
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// recursive way
void inOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // LNR
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // NLR
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // LRN
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    // Node*pre, *suc = NULL;
    cout << "Enter data to create BST" << endl;
    // 50 20 70 10 30 90 110 -1
    input(root);
    cout << "BST Printing" << endl;
    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);
    cout << "inOrder Traversal" << endl;
    inOrder(root);
    cout << endl
         << "preOrder Traversal" << endl;
    preOrder(root);
    cout << endl
         << "postOrder Traversal" << endl;
    postOrder(root);

    // cout<<endl<<minNode(root)->data<<endl;
    // cout<<endl<<maxNode(root)->data<<endl;

    // cout<<endl<<"Printing inorder predecessor and inorder successor: "<<endl;
    // findPreSuc(root, 4, pre, suc);
    // if(pre!=NULL)
    //    cout<<"predecessor: "<<pre->data<<endl;
    // else
    //    cout<<"No predecessor"<<endl;
    // if(suc!=NULL)
    //    cout<<"successor: "<<suc->data<<endl;
    // else
    //    cout<<"No successor"<<endl;
    return 0;
}
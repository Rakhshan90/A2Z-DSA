#include <iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
//recursive
node *buildTree(node *root)
{
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    root = new node(data);
    cout<<"Enter data for inserting left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
//iterative way (BFS)
node*levelOrderTraversal(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        //Previous level traverse ho chuka 
        if(temp==NULL){
            cout<<endl;   //enter
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            //if temp->left isn't NULL
            if(temp->left){
                q.push(temp->left);
            }
            //if temp->right isn't NULL
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
//recursive way (DFS)
void inOrder(node*root){
    //base case 
    if(root==NULL){
        return;
    }
    //LNR
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
//DFS
void preOrder(node*root){
    //base case
    if(root==NULL){
        return;
    }
    //NLR
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
//DFS
void postOrder(node*root){
    //base case
    if(root==NULL){
        return;
    }
    //LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//Morris Traversal -> TC:O(n), SC:O(1)
void morrisTraversal(node*root){
    if(root==NULL)
       return;
    node*curr, *pre;
    curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            //find predecessor that is rightmost child of left subtree
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                //create temporary link
                pre->right = curr;
                curr=curr->left;
            }
            else{
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}
//iterative way
void buildFromlevelOrder(node*&root){
    queue<node*>q;
    cout<<"Enter data for root :"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}
int main()
{
    node *root = NULL;

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromlevelOrder(root);
    // morrisTraversal(root);
    // cout<<endl<<"inOrder: ";
    inOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);
    // cout<<"levelOrderTraversal Printing"<<endl;
    // levelOrderTraversal(root);

    // cout<<endl<<"inOrder: ";
    // inOrder(root);
    // cout<<endl<<"preOrder: ";
    // preOrder(root);
    // cout<<endl<<"postOrder: ";
    // postOrder(root);
    
    return 0;
}
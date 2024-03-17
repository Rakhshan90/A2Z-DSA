/*
Problem statement: Given two BSTs, return elements of both BSTs in sorted form.
*/

/*
Approach: 
1. Find inorder of both the BSTs and store them in containers.
2. Iterate through both the containers and store them in another merged container in a sorted order.
3. return the merged container.

TC: O(m+n), SC: (m+n)
*/

/*
void convertBSTtoArr(Node *root, vector<int> &inorder){
        if(root == NULL) return;
        convertBSTtoArr(root->left, inorder);
        inorder.push_back(root->data);
        convertBSTtoArr(root->right, inorder);
    }
    vector<int> mergeInorders(vector<int> &inorder1, vector<int> &inorder2){
        int m = inorder1.size();
        int n = inorder2.size();
        vector<int> merged;
        int i=0, j=0;
        while(i<m && j<n){
            if(inorder1[i] <= inorder2[j]){
                merged.push_back(inorder1[i++]);
            }
            else{
                merged.push_back(inorder2[j++]);
            }
        }
        
        while(i<inorder1.size()){
            merged.push_back(inorder1[i++]);
        }
        
        while(j<inorder2.size()){
            merged.push_back(inorder2[j++]);
        }
        return merged;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> inorder1;
       convertBSTtoArr(root1, inorder1);
       vector<int> inorder2;
       convertBSTtoArr(root2, inorder2);
       return mergeInorders(inorder1, inorder2);
    }
*/
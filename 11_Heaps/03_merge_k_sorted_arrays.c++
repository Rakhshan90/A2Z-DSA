/*
Problem statement: Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

K = 4
arr[][]={{1,2,3,4},{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
*/

/*
Approach: using linkedlist and min heap [Optimized approach]
1. Push first elements of each k arrays into minHeap
2. while size of minHeap is greater than 0, pick min element form top of the minHeap and push into the ans array, finally pop out that element from minHeap.
3. Check if next element is exist in same array, push into minHeap.
4. Once you exit the while loop, return your ans array.

TC: O(k*k log k), SC: O(k*k)
*/

/*
class node{
    public:
    int i, j, data;
    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};
class compare{
    public:
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<node*, vector<node*>, compare>minHeap;
        //insert first elements of each k arrays into minHeap
        for(int i = 0; i<K; i++){
            node*newNode = new node(arr[i][0], i, 0);
            minHeap.push(newNode);
        }
        
        while(minHeap.size() > 0){
            node*temp = minHeap.top();
            ans.push_back(temp->data);
            minHeap.pop();
                
            int row = temp->i; //row index of temp
            int col = temp->j; //col index of temp
            //check if next element of temp is exist, push into minHeap
            if(col + 1 < arr[row].size()){
                node*nextNode = new node(arr[row][col+1], row, col+1);
                minHeap.push(nextNode);
            }
        }
        
        return ans;
        
    }
};
*/
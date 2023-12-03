/*
Problem statement: A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)
*/


/*
Approach 1: Brute-force
Intuition: celebrity is one whose row contains all the zeroes and col contains all the ones except the diagonal.

1. We will check for all elements, whoever satisfies the above condition will be our celebrity.
2. We will use outer loop to traverse n persons. Inside outer loop, we will use two loops one for rows and one for columns to check which person satisfies the condition.
TC : O(N^2), SC: O(1)
*/

/*
Approach 2: Using stack (Optimized)
Intuition: celebrity is one whose row contains all the zeroes and col contains all the ones except the diagonal.
1. store all the persons in stack
2. pop two persons a and b from stack while size of stack is greater than 1 and compare them. if a knows b that means a can't be celebrity so discard it and push back b to the stack, otherwise push back a to the stack and discard b.
3. when loop exit, single person will be present in stack and that will be our potential candidate. Check if this candidate is celebrity or not.
4. if all zero contains in its row and all 1 contains in its column except diagonal then the potential candidate is our celebrity, otherwise celebrity does not exist.

TC: O(N), SC: O(N)
*/

/*
class Solution 
{
    public:
    bool knows(vector<vector<int> >& M, int n, int a, int b){
        if(M[a][b] == 1) return true;
        else return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        //store all the person in stack
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(knows(M, n, a, b)) st.push(b);
            else st.push(a);
            
        }
        
        //single element present in stack is our potential candidate
        //so verify it
        int candidate = st.top();
        
        int zeroCnt = 0;
        for(int j=0; j<n; j++){
            if(M[candidate][j] == 0) zeroCnt++; 
        }
        
        int oneCnt = 0;
        for(int i=0; i<n; i++){
            if(M[i][candidate] == 1) oneCnt++;
        }
        
        if(zeroCnt == n && oneCnt == n-1) return candidate; //celebrity found
        else return -1;
        
    }
};
*/
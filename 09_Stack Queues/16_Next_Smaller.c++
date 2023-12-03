/*
Problem statemnet: Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

input: A = [4, 5, 2, 10, 8]
output: G = [-1, 4, -1, 2, 2]
*/


/*
Approach: Using stack
The stack is used to keep track of the elements that are potential NSE candidates. As we traverse the array from left to right, we keep popping elements from the stack until we find an element that is lesser than the current element. This ensures that we are only considering elements that are lesser than the current element and could potentially be its NSE. If the top element of the stack is lesser than the current element, then it is the NSE for the current element. Otherwise, if the stack becomes empty, then there is no NSE for the current element. Finally, we push the current element onto the stack.

TC: O(N), SC: O(N)
*/


/*
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int>nse(n, -1);
    stack<int>st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= A[i]) st.pop();
        if(!st.empty()) nse[i] = st.top();
        st.push(A[i]);
    }
    return nse;
}
*/
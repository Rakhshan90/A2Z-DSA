/*
Problem statement: Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

/*
Approach: Using stack
The stack is used to keep track of the elements that are potential NGE candidates. As we traverse the array from right to left, we keep popping elements from the stack until we find an element that is greater than the current element. This ensures that we are only considering elements that are greater than the current element and could potentially be its NGE. If the top element of the stack is greater than the current element, then it is the NGE for the current element. Otherwise, if the stack becomes empty, then there is no NGE for the current element. Finally, we push the current element onto the stack.

TC: O(N), SC: O(N)
*/


/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int> nge(n, -1);
        for(int i = 2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            
            if(i<n && !st.empty()) nge[i] = st.top();

            st.push(nums[i%n]);
        }
        return nge;
    }
};
*/
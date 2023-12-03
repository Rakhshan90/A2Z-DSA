/*
Problem statement: The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

input: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2]
output: [-1, 3, -1]
*/

/*
Approach 1: Brute-force approach
For each element in nums1, iterate through nums2 to find the matching element. Once we find the matching element, iterate through the remaining elements in nums2 to find the next greater element.
*/

/*
Approach 2: Using stack and map
We traverse nums2 and push each element onto the stack. If the current element is greater than the top element of the stack, we pop elements from the stack and add them to the map with the current element as the value. Once we finish traversing nums2, we iterate through nums1 and check if each element has a next greater element in the map. If it has, we store the corresponding value in the map. Otherwise, we store -1.

TC: O(N), SC: O(N)
*/

/*
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> ans;
        for(int num : nums2){
            while(!st.empty() && st.top() < num){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        for(int num : nums1){
            if(mp[num]) ans.push_back(mp[num]);
            else ans.push_back(-1);
        }

        return ans;
    }
*/
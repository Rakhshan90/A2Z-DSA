//Based on the pattern of subsequences

/*
Problem statement: Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Ex: Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

/*
Intuition: Include and Exclude the current element in the given array.

Approach : Using Recursion and Backtracking

1. Keep making exluding calls, when you are not including the current element unitl the base condition fullfilled.
2. keep making including calls, when you are including the current element unitl the base condition fullfilled.
3. Once i reaches the end of the array, base condition will fullfilled. till now, what values you have stored or may be don't have stored any values, store values of array or empty array in the answer and return from the function call (Backtrack) for finding further subsets.

TC: O(2^n), SC: O(n)
*/
/*
void recursion(vector<int> nums, int index, vector<int> temp, 
    vector<vector<int>> &ans){
        if(index>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //exclude call 
        recursion(nums, index + 1, temp, ans);
        //include call
        int num = nums[index];
        temp.push_back(num);
        recursion(nums, index + 1, temp, ans);
        temp.pop_back(); //backtracking
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        int index = 0;
        recursion(nums, index, temp, ans);
        return ans;
    }
*/
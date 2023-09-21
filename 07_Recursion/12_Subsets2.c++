/*
Problem statement:
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*
Approach : Recursion and Backtracking
1. Before starting the recursive call make sure to sort the elements because the ans should 
contain unique subsets.

2. Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element of our subsets.

3. Check if the current index value can be added to our ds. If yes add it to the ds and move the index by 1. while moving the index skip the consecutive repeated elements because they will form duplicate subsets.

4. Call the recursive call for f(i + 1 , ds, ans) after the call make sure to pop the element from the ds when you backtrack.

Base Condition:
Whenever for loop exit add the ds to the ans.

Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/

/*
void findSubsets(int index, vector<int> &ds, vector<int>& nums, 
    vector<vector<int>> &ans){
        ans.emplace_back(ds);
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            ds.emplace_back(nums[i]);
            findSubsets(i+1, ds, nums, ans);
            //backtrack
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int>ds;
        findSubsets(0, ds, nums, ans);
        return ans;
    }
*/
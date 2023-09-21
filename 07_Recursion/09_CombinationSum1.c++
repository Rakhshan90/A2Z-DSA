/* 
Problem statement:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

/*
Approach: Using pick and not-pick approach 
1. When we are picking current element, we will store current element in ds, and reduced target by the current element. Picking call only possible when target will be greater or equal than current element. 
2. A/C to problem we can pick same number unlimited number of times. So we should interested in same index and call recursion for the same index [Picking].
3. When we are not picking current element, that means we are not interested in picking so we call recursion for the next index.
4. Once index reaches the end of the array, base condition will fullfilled. check if target becomes 0 then current state of ds is our possible combination so, stored it in answer.

TC: O(2^t*k), SC: ~= O(k*x). where k is size of each combination, and x is the total combination.
*/

/*
void findCombinations(int index, vector<int>& candidates, int target, 
    vector<int> &ds, vector<vector<int>> &ans){
        if(index >= candidates.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        //pick call
        if(target >= candidates[index]){
            target-=candidates[index];
            ds.push_back(candidates[index]);
            findCombinations(index, candidates, target, ds, ans);
            //backtrack
            target+=candidates[index];
            ds.pop_back();
        }
        //unpick call
        findCombinations(index+1, candidates, target, ds, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findCombinations(0, candidates, target, ds, ans);
        return ans;
    }
*/
/*
Problem statement:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/

/*
Approach : Recursion and Backtracking
1. Before starting the recursive call make sure to sort the elements because the ans should 
contain the combinations in sorted order and should not be repeated.

2. Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element of our subsequence.

3. Check if the current index value can be added to our ds. If yes add it to the ds and move the index by 1. while moving the index skip the consecutive repeated elements because they will form duplicate sequences.

4. Reduce the target by arr[i],call the recursive call for f(i + 1,target – 1,ds,ans) after the call make sure to pop the element from the ds if basic condition satisfied.

5. if(arr[i] > target) then terminate the recursive call because there is no use to check as the array is sorted in the next recursive call the index will be moving by 1 all the elements to its right will be in increasing order.

Base Condition:
Whenever the target value is zero add the ds to the ans return.

TC: O(2^n*k), SC: ~= O(k*x). where k is size of each combination, and x is the total combination.
*/


/*
void findCombinations(int index, int target, vector<int> &ds, 
    vector<int>& candidates, vector<vector<int>> &ans){
        if(target==0){
            ans.emplace_back(ds);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.emplace_back(candidates[i]);
            findCombinations(i+1, target-candidates[i], ds, 
            candidates, ans);
            //backtrack
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<vector<int>>ans;
       vector<int>ds;
       findCombinations(0, target, ds, candidates, ans);
       return ans; 
    }
*/
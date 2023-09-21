/*
Problem statement: 
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

/*
Approach : Recursion and Backtracking
1. Initialized an nums array with values from 1 to 9. 

2. Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element of our subsequence.

3. Check if the current index value can be added to our ds. If yes add it to the ds and move the index by 1. while moving the index skip the consecutive repeated elements because they will form duplicate sequences.

4. Reduce the n by nums[i] and k by 1,call the recursive call for f(i + 1, k-1, n – nums[i],ds,ans) after the call make sure to pop the element from the ds if basic condition satisfied.

5. if(arr[i] > target) then terminate the recursive call because there is no use to check as the array is sorted in the next recursive call the index will be moving by 1 all the elements to its right will be in increasing order.

Base Condition:
Whenever the k becomes zero check again for valid combination, if n is zero we got our valid combination then add the ds to the ans return.

TC: O(2^n*k), SC: ~= O(k*x). where k is size of each combination, and x is the total combination.
*/

/*
void findCombinations(int index, vector<int> &ds, int k, int n, 
    vector<int> &nums, vector<vector<int>> &ans){
        if(k==0){
            if(n==0) ans.emplace_back(ds);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            if(nums[i]>n) break;
            ds.emplace_back(nums[i]);
            findCombinations(i+1, ds, k-1, n-nums[i], nums, ans);
            //backtrack
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>ds;
        vector<int>nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        findCombinations(0, ds, k, n, nums, ans);
        return ans;
    }
*/
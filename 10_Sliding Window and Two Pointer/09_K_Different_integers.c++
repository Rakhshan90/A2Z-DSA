/*
Problem statement: Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
*/

/*
Approach: Sliding window (Optimized)
TC: O(n), SC: O(1)
*/

/*
int atmost(vector<int>& nums, int k){
        int i = 0, j = 0, count = 0;
        unordered_map<int, int> charFreq;
        while(j < nums.size()){
            charFreq[nums[j]]++;
            while(charFreq.size() > k){
                charFreq[nums[i]]--;
                if(charFreq[nums[i]] == 0) charFreq.erase(nums[i]);
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
*/
/*
Problem statement: Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
*/

/*
Approach: sliding window and two pointers (Optimized)

Define variable:
j=0-> To Shrink Window Size,
max_con_one=0 -> Count Maximum consecutive One's,
count_zero=0 -> count number of zeros flipped.
Traverse over the Array
a)if element is Zero -> Increase ZeroCount.
b)if The Zero Count Exceed k(Max Zero) then
Shrink Our Window Size & update j to Shrink Window Size.
c)Update result in Every Step.
return max_con_one.

TC: O(n), SC: O(1)

*/

/*
int longestOnes(vector<int>& nums, int k) {
        int max_con_one = 0, zero_cnt = 0;
        int j = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) zero_cnt++;

            // if The Zero Count Exceed k(Max Zero) then Shrink Our Window Size
            while(zero_cnt > k){
                // To consider other zeroes which will be present towards right, decrease zero_cnt
                if(nums[j] == 0) zero_cnt--;

                // increment j to shrink the window size
                j++;
            }

            // Update result in Every Step
            int window_length = i - j + 1;
            max_con_one = max(max_con_one, window_length);
        }
        return max_con_one;
    }
*/
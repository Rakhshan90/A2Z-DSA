/*
Problem statement: Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/

/*
Intuition: We can solve this problem by using maths concept of calculating exact(n).
exact(n) = atmost(n) - atmost(n-1)

Approach:

atmost()
Define variable:
i=0-> To Shrink Window Size,
j=0-> To iterate over the given array,
odd_cnt = 0 -> To count odd numbers.
count = 0 -> To track count of subarrays whose contains odd elements.
a)nums[j] is odd we will increment oddd_cnt 
b)while odd_cnt is greater than k ,  
Shrink Our Window Size & update i to Shrink Window Size.
c)calculate count after each step
return count.

numberOfSubarrays()
we calculate all the subarrays with atmost k. Then substract no. of subarrays with atmost k-1. 

TC: O(n), SC: O(1)
*/

/*
int atmost(vector<int>& nums, int k){
        int i = 0, j = 0, count = 0, odd_cnt = 0;
        while(j < nums.size()){
            if(nums[j] % 2 != 0) odd_cnt++;

            while(odd_cnt > k){
                if(nums[i] % 2 != 0) odd_cnt--;
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
*/
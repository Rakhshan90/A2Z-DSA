/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
*/

/*
Intuition: We can solve this problem by using maths concept of calculating exact(n).
exact(n) = atmost(n) - atmost(n-1), Let say for n = 2,
exact(2) = atmost(2) - atmost(2-1)
exact(2) = 0, 1, 2   - 0, 1
Let assume that, 0, 1, 2 are x, y and z respectively
exact(2) = x, y, z   - x, y  =  z, which is 2.

Approach : Sliding window (Optimized) 

atmost()
Define variable:
i=0-> To Shrink Window Size,
j=0-> To iterate over the given array,
sum = 0 -> To track sum of subarray
count = 0 -> To track count of subarrays whose sum is equal to goal.
a)add nums[j] to sum 
b)while sum is greater than goal and make sure i <= j,  
Shrink Our Window Size & update i to Shrink Window Size.
c)calculate count after each step
return count.


numSubarraysWithSum()
we calculate all the subarrays with atmost sum goal. Then substract no. of subarrays with atmost sum goal-1. 

TC: O(n), SC: O(1)
*/

/*
int atmost(vector<int>& nums, int goal){
        int i = 0, j = 0, count = 0, sum = 0;
        while(j < nums.size()){
            sum += nums[j];

            while(i <= j && sum > goal){
                sum -= nums[i];
                i++;
            }

            count += j - i + 1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
*/
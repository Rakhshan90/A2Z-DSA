/*
Find the length of the longest subarray in which the sum of elements is equal to 'K'.
If there is no subarray whose sum is 'K' then you should return O.
Remember given input array may contain zero, negative, and positive values.
*/

/*
Approach: PreSum [reverse engineering] - Optimal solution
1. Maintain a prefix sum map to keep track of the sum of all subarrays up to a given index.
2. Initialize the current sum and maximum length to 0.
3. Iterate over the array and update the current sum.
4. If the current sum is equal to k, update the maximum length to the current index + 1.
5. Check if the prefix sum map contains a preSum that is equal to the current sum - k. If it does, update the maximum length to the current index - the index of the preSum in the prefix sum map.
6. Add the current sum to the prefix sum map, if and only if current sum previously not present in prefix sum map.
7. Return the maximum length. 

TC: O(N2) in worst case and O(N) in avg case, SC: O(N)
*/
/*
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    int sum=0, maxLen=0;
    unordered_map<int, int>preMap;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum==k) maxLen = max(maxLen, i+1);
        int preSum = sum - k;
        if(preMap.find(preSum) != preMap.end()) maxLen = max(maxLen, i-preMap[preSum]);
        if(preMap.find(sum) == preMap.end()) preMap[sum] = i;
    }
    return maxLen;
}
*/
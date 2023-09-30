/*
You are given an array 'a' of size 'n' and an integer 'k'. Find the length of the longest subarray of 'a' whose sum is equal to 'k'.
Remember given input array may contain zero, and positive values. It will not contain negative values.
*/

/*
Approach 1: same prefix sum approach used to solve this problem.
*/

/*
since, in this problem, given array contain only positive, and zero values. so we can optimize first solution.
Approach 2: Two Pointers

We are using two pointers i.e. left and right. The left pointer denotes the starting index of the subarray and the right pointer denotes the starting index. Now as we want the longest subarray, we will move the right pointer in a forward direction every time adding the element i.e. a[right] to the sum. But when the sum of the subarray crosses k, we will move the left pointer in the forward direction as well to shrink the size of the subarray as well as to decrease the sum. Thus, we will consider the length of the subarray whenever the sum becomes equal to k.

TC:O(2*n), SC:(1)
*/

/*
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0, maxLen = 0;
    long long sum = a[0];
    while(right<a.size()){
        while(left<=right && sum > k){
            sum-=a[left];
            left++;
        }
        if(sum==k) {
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        sum+=a[right];
    }
    return maxLen;
}
*/
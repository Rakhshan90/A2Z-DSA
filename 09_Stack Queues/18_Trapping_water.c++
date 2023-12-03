/*
Problem statement: 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

/*
Approach 1: Brute-Force
For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.

TC: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop
SC: O(1)
*/

/*
#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
*/

/*
Approach 2: Optimized (Two Pointers)
Intuition: We need a minimum of leftMax and rightMax.
Approach: Take 2 pointers l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively. Take two variables leftMax and rightMax and initialize them to 0. If height[l] is less than or equal to height[r] then if leftMax is less than height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the right i.e l++. If height[r] is less than height[l], then now we are dealing with the right block. If height[r] is greater than rightMax, then update rightMax to height[r] else add rightMax-height[r] to the final answer. Now move r to the left. Repeat these steps till l and r crosses each other.

TC: O(N), SC: O(1)
/*
int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxLeft = 0, maxRight = 0;
        int water = 0;
        while(l<=r){
            if(height[l] <= height[r]){
                if(height[l] >= maxLeft) maxLeft = height[l];
                else water += maxLeft - height[l];
                l++;
            }
            else{
                if(height[r] >= maxRight) maxRight = height[r];
                else water += maxRight - height[r];
                r--;
            }
        }
        return water;
    }
*/
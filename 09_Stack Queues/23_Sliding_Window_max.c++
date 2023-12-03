/*
Problem statement:
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/

/*
Approach: Using monotonically decreasing dequeue (Optimized)

 When shifting our window, we push the new element in from the rear of our de-queue. Every time before entering a new element, we first need to check whether the element present at the front is out of bounds of our present window size. If so, we need to pop that out. Also, we need to check from the rear that the element present is smaller than the incoming element. If yes, there’s no point storing them and hence we pop them out. Finally, the element present at the front would be our largest element.
*/

/*
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int> ans;
        for(int i=0; i<n; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            //when element present at the front is out of bounds of our present window size. so we need to pop out.
            if(!dq.empty() && i - k == dq.front()) dq.pop_front();

            dq.push_back(i);

            //whenever given size of window is completed, we will got our largest element from fornt of the deque. 
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
}
*/
/*
Problem statement: Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

/*
Approach 1: max heap
1. push all the elements into maxHeap.
2. keep popping elements until kth largest element is found on top of the maxHeap.

TC: O(n log n), SC: O(n)
*/

/*
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(auto num:nums){
            maxHeap.push(num);
        }

        int top = -1;
        while(!maxHeap.empty() && k != 0){
            top = maxHeap.top();
            maxHeap.pop();
            k--;
        }
        return top;
    }
*/

/*
Approach 2: min heap (Optimized)
Intuition: In previous approach, we are storing all the elements in the maxHeap which takes O(n) SC. 
But, If K is significantly smaller than N we can avoid to process all elements using a max heap. 
We can only maintains the K smallest elements in the min heap. However, the efficiency depends on the relationship between K and N. If K is close to N, the first approach might be more efficient.

1. push first k elements into the minHeap.
2. compare remaining elements, if current element is greater than element at the top of the minHeap, we pop and push current element into the minHeap, otherwise do nothing.
3. Once you process the remaining elements answer will be the top of the minHeap.


TC:  O((N - K) * log(K)), SC: O(k)

*/

/*
 int findKthLargest(vector<int>& nums, int k) {
         //step1: min heap
        priority_queue<int, vector<int>, greater<int> >minHeap;
        for(int i=0; i<k; i++){
            minHeap.push(nums[i]);
        }
        //step2: remaining element process
        int size = nums.size();
        for(int i=k; i<size; i++){
            if(nums[i]>minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        //step3:
        int ans = minHeap.top();
        return ans;
    }
*/
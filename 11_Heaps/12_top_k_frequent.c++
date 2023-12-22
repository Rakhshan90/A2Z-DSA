/*
Problem statement: Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

/*
Approach: hashmap and max heap [Optimized]

Frequency Map:
1. Create an unordered map (freq) to store the frequency of each element in the input vector nums.

Max Heap Construction:
1. Create a max heap (priority_queue with a pair of frequency and element) to efficiently retrieve the elements with the highest frequencies.
2. Iterate over the freq map and insert pairs of the form (frequency, element) into the max heap.

Retrieve Top K Elements:
1. While the max heap is not empty and k is not 0:
2. Pop the top element from the max heap, which is the element with the highest frequency.
3. Push this element into the result vector ans.
4. Decrement k to keep track of the number of elements left to retrieve.

Return Result:
1. After the loop, return the vector ans containing the top k frequent elements.

Time Complexity:
The time complexity of this algorithm is O(N * log(M)), where N is the number of elements in the input vector nums, and M is the number of unique elements (distinct values) in nums. This is because each insertion and extraction from the max heap takes O(log(M)) time, and the loop iterates over the distinct values.

Space Complexity:
The space complexity is O(M), where M is the number of unique elements in nums. This is due to the space required for the frequency map and the max heap.

This approach efficiently finds the top k frequent elements in the given array.
*/

/*
vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> maxHeap;
        for(auto num:nums){
            freq[num]++;
        }
        for(auto it:freq){
            maxHeap.push({it.second, it.first});
        }
        while(!maxHeap.empty() && k != 0){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }
        return ans;
    }
*/
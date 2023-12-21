/*
Problem statement:
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
*/

/*
Approach: minHeap
1. Take a priority queue (min heap based) and push all the elements of the given array.
2. keep only k elements in the min heap. Pop all others
3. each time add() function called ,
4. push the value in priority queue
5. if we have more than k elements in queue , pop it
6. return the top of the queue. [kth largest element]


Time complexity:
O(N⋅log⁡(N)+M⋅log⁡(k))
Nlog(N) -> pushing all value of nums in queue.
Mlog(k) -> M calls for add() function and for each call, pushing element in a queue of size k.

Space complexity:
O(N)
*/

/*
class KthLargest {
public:
    int kNums;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        kNums = k;
        for(auto num:nums){
            minHeap.push(num);
        }
        
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size() > kNums){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
*/
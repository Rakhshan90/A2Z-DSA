/*
Problem statment: The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/

/*
Approach 1: using sorting method [Brute-force]
addNum: 
1. push curr element into arr.
2. sort the entire arr.

findMedian:
1. check if size of arr is odd return middle element as median.
2. if size of arr is even return average of two middle elements as median.
*/

/*
class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin(), arr.end());
    }
    
    double findMedian() {
        int n = arr.size();
        if(n % 2 != 0) return arr[n/2];
        else{
            int first = arr[n/2];
            int second = arr[n/2 - 1];
            double avg = (first + second) / 2.0;
            return avg; 
        }
    }
};
*/

/*
Approach 2: Use of maxHeap and minHeap [Optimized]

Use of Two Heaps:
1. Maintain two heaps, a max heap (maxHeap) to store the smaller half of the numbers and a min heap (minHeap) to store the larger half.
2. The max heap will be used to keep track of the left half of the numbers, and the min heap will be used to keep track of the right half.

Maintaining Median:
1. The median is the middle element of the sorted list of numbers. If the number of elements is even, it is the average of the two middle elements.
2. If both heaps have the same size, the median is the average of the tops of both heaps.
3. If the max heap is larger, the median is the top of the max heap.
4.If the min heap is larger, the median is the top of the min heap.

Adding a Number:
1. Compare the sizes of the two heaps to determine which one should be modified.

2. If the sizes are the same, compare the new number (num) with the current median:
   1. If num is greater than the median, insert it into the min heap and update the median.
   2. If num is smaller than or equal to the median, insert it into the max heap and update the median.

3. If the max heap is larger, compare num with the median:
   1. If num is greater than the median, insert it into the min heap and update the median.
   2. If num is smaller than or equal to the median, insert the top of the max heap into the min heap, pop the max heap, insert num into the man heap, and update the median.

4. If the min heap is larger, compare num with the median:
   1. If num is greater than the median, insert the top of the min heap into max heap, pop min heap, insert num into the min heap, 
   and update the median.
   2. If num is smaller than or equal to the median, insert num into the max heap, and update the median.

Finding the Median:
1. Return the current median.

TC: O(n log n), SC: O(n)
*/

/*
class MedianFinder {
public:
    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int> , greater<int>> minHeap; 
    MedianFinder() {
        
    }

    int signum(int a, int b){
        if(a == b) return 0;
        if(a > b) return 1;
        else return -1;
    }
    
    void addNum(int num) {
        switch(signum(maxHeap.size(), minHeap.size())){
            case 0:
            if(num > median){
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                maxHeap.push(num);
                median = maxHeap.top();
            }
            break;

            case 1:
            if(num > median){
                minHeap.push(num);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            break;

            case -1:
            if(num > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            else{
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            break;
        }
    }
    
    double findMedian() {
        return median;
    }
};
*/
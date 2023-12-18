/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
Return the least number of units of times that the CPU will take to finish all the given tasks.

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
*/

/*
Approach: using maxHeap [Optimized approach]
1. Frequency Map:
Create an unordered map (charFreq) to store the frequency of each task in the input vector.

2. Priority Queue (Max Heap):
Create a max heap (maxHeap) using a priority queue to prioritize tasks based on their frequencies.

3. Populating the Max Heap:
Iterate over the tasks vector and populate the max heap with pairs of the form (frequency, task).
The priority is given to the task with the highest frequency.

4. Greedy Interval Execution:
Initialize a variable ans to 0 to keep track of the total number of intervals needed.
I
5. interval Execution Loop:
Continue the loop until the max heap is not empty.
If the top task in the max heap has a frequency of 1, it means there are no more instances of this task left to execute.
Increment ans by the size of the max heap (all remaining tasks).
Break out of the loop.
Otherwise, execute tasks in intervals:
Create a vector v to store tasks for the current interval.
Pop the top task from the max heap and add it to v.
Increment ans by 1.
For the next n intervals, pop tasks from the max heap and add them to v if available.
Increment ans by the number of intervals executed.
Update the frequency of each task in v and push them back to the max heap.

6. Return Result:
After the loop, return the total number of intervals (ans).

TC: O(N * n * Log(N))
SC: O(N)
*/

/*
int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> charFreq;
        for(auto i:tasks){
            charFreq[i]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for(auto j:charFreq){
            maxHeap.push({j.second, j.first});
        }
        int ans = 0;
        while(maxHeap.size() > 0){
            if(maxHeap.top().first == 1){
                ans += maxHeap.size();
                break;
            }
            vector<pair<int, char>> v;
            v.push_back(maxHeap.top());
            maxHeap.pop();
            ans += 1;
            for(int i=0; i<n; i++){
                if(maxHeap.size() > 0){
                    v.push_back(maxHeap.top());
                    maxHeap.pop();
                }
                ans++;
            }
            for(auto x:v){
                if(x.first > 1){
                    maxHeap.push({x.first-1, x.second});
                }
            }
        }
        return ans;
    }
*/
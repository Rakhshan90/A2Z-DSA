/*
Problem statement: You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/

/*
Approach: min heap [Optimized approach]
1. Push first node of each list into min heap.
2. Create an empty ans list
3. while size of minHeap is greater than 0, pick min node form top of the minHeap and add into the ans list, finally pop out that min node from minHeap.
3. Check if next node is exist in same list, add into minHeap.
4. Once you exit the while loop, return your ans list.

TC: O(k*k log k), SC: O(k)

*/

/*
class compare{
    public:
    bool operator()(ListNode*a, ListNode*b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int n = lists.size();

        // Push first node of each list into min heap
        for(int i=0; i<n; i++){
            if(lists[i] != nullptr) minHeap.push(lists[i]);
        }
        
        //create ans list
        ListNode*head = nullptr;
        ListNode*tail = nullptr;

        while(minHeap.size() > 0){
            ListNode*top = minHeap.top();
            minHeap.pop();
            if(top->next != nullptr) minHeap.push(top->next);
            if(head == nullptr){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }
        }
        return head; //return head of ans list
    }
};
*/
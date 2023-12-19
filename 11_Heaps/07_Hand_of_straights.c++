/*
Problem statement: Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
*/

/*
Approach: ordered map and minHeap (Optimized approach)
1. Create an ordered map to store frequencies of each element in sorted order because we need consecutive order of elments to form group of groupSize.
2. Create a minHeap to find min element in O(log n) time because each group will have first element is minimum.
3. push keys of map into minHeap because we do not need duplicates in minHeap.
4. while minHeap is not empty, take top element from minHeap which will be first element of a group, then iterate 
over map to find gorup of gorupSize only.
5. check if element i is not present in map, then return false because group can not be form. otherwise decrement
the frequency of element i from map.
6. check if frequency of element i is 0, then remove element i from minHeap.
7. Once minHeap is empty, then return true because we did not get false. Hence Group can be form.

TC: O(n log n), SC: O(n)
*/

/*
bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto x:hand){
            mp[x]++;
        }
        for(auto it:mp){
            minHeap.push(it.first);
        }
        while(!minHeap.empty()){
            int first_top = minHeap.top();
            for(int i = first_top; i < first_top + groupSize; i++){
                if(mp.find(i) == mp.end()) return false;
                mp[i]--;
                if(mp[i] == 0){
                    minHeap.pop();
                }
            }
        }
        return true;
    }
*/
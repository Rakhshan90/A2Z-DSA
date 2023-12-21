/*
Problem statement: There are given n ropes of different lengths, we need to connect these ropes into
one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.
*/


/*
Approach: minHeap
Min Heap Construction:
1. Create a min heap (priority_queue with greater comparator) to efficiently retrieve the minimum length ropes.
2. Insert all elements from the array arr into the min heap.

Connect Ropes:
1. While the min heap has more than one element (more than one rope):
2. Pop the top element (rope1) from the min heap. This represents the shortest available rope.
3. Pop the new top element (rope2) from the min heap. This represents the second shortest available rope.
4. Calculate the new length of the rope obtained by connecting rope1 and rope2 (newRope = rope1 + rope2).
5. Add the cost of connecting these two ropes to the total cost.
6. Push the new rope length (newRope) back into the min heap.

Return Result:
1. After the loop, return the total cost, which represents the minimum cost to connect all the ropes.

TC: O(n log n), SC: O(n)
*/

/*
#include<bits/stdc++.h>
int minCost(int arr[], int n)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i = 0; i < n; i++){
		minHeap.push(arr[i]);
	}
	int totalCost;
	while(minHeap.size() >= 2){
		int rope1 = minHeap.top(); 
		minHeap.pop();
		int rope2 = minHeap.top(); 
		minHeap.pop();
		int newRope = rope1 + rope2;
		totalCost += newRope;
		minHeap.push(newRope);
	}
	return totalCost;
}
*/
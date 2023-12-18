/*
Problem statement: Given an array of integers 'ARR'of size 'N'. Replace each element of this array with its corresponding rank and return the array.
The rank of an element is an integer between 1 to 'N' inclusive that represents how large the element is in comparison to other elements of the array. The following rules can also define the rank of an element:
1. It is an integer starting from 1.
2. The larger the element, the larger the rank. If two elements are equal, their
rank must be the same.
3. It should be as small as possible.

Input:  1 2 6 9 2 
Output: 1 2 3 4 2
*/

/*
Approach: min heap
1. Create minHeap of type pair for storing both element and thier corresponding index. 
2. store all elements and their corresponding indexes in minHeap.
3. while size of minHeap is greater or equal than 2, pick min value and it's index form minHeap
4. check if value and top of minHeap is not equal thats means we need to increment its rank, but before that we need to add rank to the arr[index] and increment the rank++.
5. if value and top of minHeap is same thats means we don't need to increment rank, we will just add rank to the 
arr[index]
6. Once you exist the while loop, minHeap still exist one element left, which we will handle separately, so just add
rank to the arr[minHeap.top().second]
7. return arr.

TC: O(n log n), SC: O(n)
*/

/*
#include<bits/stdc++.h>
vector<int> replaceWithRank(vector<int> &arr, int n) {
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minHeap;
    //store all {element, index} into minHeap
    for(int i=0; i<n; i++){
        minHeap.push(make_pair(arr[i], i));
    }
    
    int rank = 1;
    while(minHeap.size() >= 2){
        int value = minHeap.top().first;
        int index = minHeap.top().second;
        minHeap.pop();

        if(value != minHeap.top().first){
            arr[index] = rank;
            rank++;
        }
        else{
            arr[index] = rank;
        }
    }

    arr[minHeap.top().second] = rank;
    return arr; 
}
*/
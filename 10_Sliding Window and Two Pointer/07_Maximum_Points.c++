/*
Problem statement:  There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12

By using the below approach,
Explanation: First k elements in our window are [1, 2, 3] [] -> res = 1+2+3 = 6
                elements in our next window are [1, 2] [1] -> res = 1+2+1 = 3
                elements in our next window are [1] [1, 6] -> res = 1+1+6 = 8
                elements in our next window are [] [1, 6, 5] ->res = 1+6+5 = 12. So, Final answer is 12.
*/

/*
Approach: Sliding Window (Optimized)

What we do is we initialize a window of size k...
Now, since we can select either from the start or from the end, we only have access to either the first k items or last k items, and hence we are trying to limit our access using this window...
So, we include all the elements from start in our window, till its full...
The sum of elements at each instance in our window will be kept track of using another variable that will store our result.
Now, we remove the last element from our window, and add the last unvisited element of our cardPoints array... Similarly we keep on removing 1 element from our window and start adding the last unvisited element of our cardPoints array...
We keep doing this until we reach the start of our array, in this way we have covered all our possible picks...

TC: O(k), SC: O(1)
*/

/*
int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int res = 0;
        // First k elements in our window
        for(int i=0; i<k; i++) res += cardPoints[i];
        
        int curr = res;
        for(int i=k-1; i>=0; i--){
            //We remove the last visited element and add the non-visited element from the last
            curr -= cardPoints[i];
            curr += cardPoints[n - k + i];

            //We check the maximum value any possible combination can give
            res = max(res, curr);
        }
        return res;
    }
*/
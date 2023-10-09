/*
Problem statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Ex: (1, 3), (2, 6), (8, 9), (9, 11), (8, 10), (2, 4), (15, 18), (16, 17)
output: (1, 6), (8, 11), (15, 18)
*/

/*
Approach 1: Using two loops

The intuition of this approach is pretty straightforward. We are just grouping close intervals by sorting the given array. After that, we merge an interval with the other by checking if one can be a part of the other interval. For this checking, we are first selecting a particular interval using a loop and then we are comparing the rest of the intervals using another loop.

1. Sort the intervals in ascending order by their start times.
2. Iterate over the sorted intervals:
3. If the current interval overlaps with the previous interval, merge them into a single interval.
4. Otherwise, add the previous merged interval to the output list.
5. Repeat step 3, 4 until no intervals left for merging.
6. Return the output list.

TC:O(N logN) + O(2N), SC: O(N)
*/
/*
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() && ans.back()[1] >= end) continue;

            for(int j=i+1; j<n; j++){
                if(intervals[j][0] <= end) end = max(end, intervals[j][1]);
                else break;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
*/

/*
Approach 2: In single iteration

Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our answer list.

TC: O(N logN) + O(N), SC: O(N)
*/
/*
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(ans.empty() || ans.back()[1] < start)
                ans.push_back(intervals[i]);
            else ans.back()[1] = max(ans.back()[1], end);
        }
        return ans;
    }
*/
/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
*/

/*
Approach: Using Stack (Optimized)
This approach is using concept of Next smaller element to the left and next smaller element to the right.
We will calculate next smaller element to the left and next smaller element to the right for each element. But we will store indexes rather than elements in the NSL and NSR arrays. For any element if next smaller element to the left is not exist we will take -1 for that element and if next smaller element to the right is not exist we will take size of the array for that element.

After generating the NSL and NSR arrays.
For each element, We will calculate area of rectangle = length * breadth and consider the maximum one.
length of current element will be the value of current element in the heights array and breadth of current element will be the index of the next smaller element to the right - index of next smaller element to the left - 1.

TC: O(N), Sc:O(N)
*/

/*
vector<int>getNSL(vector<int>& heights, int n){
        stack<int>st;
        vector<int>NSL(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) NSL[i] = st.top();
            st.push(i);
        }
        return NSL;
    }
    vector<int>getNSR(vector<int>&heights, int n){
        stack<int>st;
        vector<int>NSR(n, n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            if(!st.empty()) NSR[i] = st.top();
            st.push(i);
        }
        return NSR;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>NSL = getNSL(heights, n);
        vector<int>NSR = getNSR(heights, n);
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];
            int b = NSR[i] - NSL[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
*/
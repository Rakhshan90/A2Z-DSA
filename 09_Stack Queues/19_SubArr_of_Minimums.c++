/*
Problem statement:
*/


/*
Approach 1: Brute-Force
For each element we will generate subarrays and check how many arrays are there in which current element is minimum. We will take count for which element is smaller in number of subarrays and add the count to the sum. We will repeat this process and return the final sum as our answer.
TC: O(n^3), SC: O(1)
*/

/*
Approach 2: Optimized 
This approach is using concept of Next smaller element to the left and next smaller element to the right.
We will calculate next smaller element to the left and next smaller element to the right for each element. But we will store indexes rather than elements in the NSL and NSR arrays. For any element if next smaller element to the left is not exist we will take -1 for that element and if next smaller element to the right is not exist we will take size of the array for that element.

After generating the NSL and NSR arrays.
For each element, we will determines the number of subarrays in which that element appear as minimum then we will add that element with number of counts into sum.
To find count we will multiply the ls and rs which are number of subarrays to the left in which the element is smaller and number of subarrays to the right in which the element is smaller.

To calculate ls and rs, ls = indexOf(element) - indexOf(NSL)
                        rs = indexOf(NSR) - indexOf(element) 

TC: O(3n) -> O(n), SC: O(n)
*/

/*
vector<int>getNSL(vector<int> &arr, int n){
        stack<int>st;
        vector<int>NSL(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()){
                NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    }
    vector<int>getNSR(vector<int> &arr, int n){
        stack<int>st;
        vector<int>NSR(n, n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()){
                NSR[i] = st.top();
            }
            st.push(i);
        }
        return NSR;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int mod = 1e9+7;
        vector<int>NSL = getNSL(arr, n);
        vector<int>NSR = getNSR(arr, n);
        
        for(int i=0; i<n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long cnt = ls*rs;
            long long totalSum = arr[i]*cnt;
            sum = (sum + totalSum)%mod;
        }
        return sum;
    }
*/
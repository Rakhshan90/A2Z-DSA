/*
Problem statement: You are given an array 'arr' of length 'N'.>
You are given 'q' queries, and for each query, you are given an index(O-
based indexing).>
Answer to each query is the number of the strictly greater elements to the
right of the given index element.>
You must return an array 'answer of length 'N', where 'answer[i]' is the
answer to the 'ith' query.>

input: arr = [5, 2, 10, 4], query = [0, 1]
output: ans[1,  2]
*/

//TC: O(m*n), where m is the length of query, n is the length of arr.
//SC : O(n)

/*
vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    vector<int>ans;
    for(int j=0; j<query.size(); j++){
        int cnt = 0;
        int element = arr[query[j]];
        for(int i=query[j]+1; i<arr.size(); i++){
            if(arr[i] > element) cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}
*/
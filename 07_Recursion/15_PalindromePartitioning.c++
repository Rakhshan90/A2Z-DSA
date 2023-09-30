/*
Problem statement: Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/

/*
Approach: "choices of picking" through recursion and backtracking

1. Define a function that checks for valid palindrome partitioning whether it possible.
2. we will be having choices of index form index to size-1 where partition possible. 
3. if partition possible from index to i, we will store valid palindrome substring string from index to i into path.
4. make recursive call for next index to find more such path i.e, findPartitions(index+1, s, path, ans)
5. When you return from the recursive call, perform backtrack to find remaining valid palindrome partitions.  
6. Base case: Whenever index reaches to the size of the given string s, store current path i.e, valid partition in answer, and return.

TC: O(O( (2^n) *k*(n/2) )), SC: (k*x), 
Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/

/*
bool isValidPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void findPartitions(int index, string s, vector<string> &path, 
    vector<vector<string>> &ans){
        if(index>=s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(isValidPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                findPartitions(i+1, s, path, ans);
                //backtrack
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>path;
        findPartitions(0, s, path, ans);
        return ans;
    }
*/
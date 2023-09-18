/*
Problem statement : Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
ex: n=2, output: "(()), ()()"
*/

/*
Approach : Using Recursion and Backtracking
1. Take two variables open and close for counting open and close parentheses.
2. if open < n, keep concatenating open parentheses in string s and incrementing variable open using recursion.
3. if close < open, keep concatenating close parentheses in string s and incrementing variable close using recursion.
4. if open == n && close == n, that means base condition is fullfilled, store the current well-formed parentheses into ans and return from the function call.
5. Perform backtracking and pop the last character from the string s simultaneously.

TC: O(2^N), SC: O(N)
*/
/*
void recursion(int open, int close, int n, string &s, 
    vector<string> &ans){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+="(";
            recursion(open+1,  close, n, s, ans);
            s.pop_back();
        }
        if(close<open){
            s+=")";
            recursion(open, close+1, n, s, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        recursion(0, 0, n, s, ans);
        return ans;
    }
*/
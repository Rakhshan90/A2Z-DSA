/* 
Problem statement : You have been given an integer 'N'. Your task is to generate and return all binary strings of length 'N' such that there are no consecutive 1's in the string.
A binary string is that string which contains only 'O' and '1'.
*/

/*
Intuition : If a string ends with 0 we can add both 0 and 1 after it, but if the string ends with 1 we can add only 0 after it. checks if the last character of s is '0'. If the last character is '0', it means there are no consecutive '1's before it, making it a valid position to add '1'.

Approach: Using Recursion + Backtracking
1. concatenate zero to string s, and make recursive call until base condition matches.
1. if base condition matches then store the posible string s into the ans vector and return form the function call (backtracking).
2. As you return from the fucntion call (backtracking) pop the last character from the string s
3. checks if the last character of s is '0' or s is empty, it means there are no consecutive '1's before it, making it a valid position to add '1'. make recursive call until base condition matches.
TC: O(2^N), SC: O(N) 
*/
/*
void recursion(int cnt, int N, string &s, vector<string> &ans){
    if(cnt==N){
        ans.push_back(s);
        return;
    }
    s+="0";
    recursion(cnt+1, N, s, ans);
    s.pop_back();

    if(s.empty() || s.back()=='0'){
        s+="1";
        recursion(cnt+1, N, s, ans);
        s.pop_back();
    }
}
vector<string> generateString(int N) {
    string s;
    vector<string> ans;
    recursion(0, N, s, ans);
    return ans;
}
*/
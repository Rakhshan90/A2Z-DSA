/*
Problem statement: Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
*/

/*
Approach: Sliding window (Optimized)

When we get the 1st window, containing a, b, and c, 
then the number of valid substrings will be: 1 + (remaining characters outside of this window towards right).
For eg: consider the 1st window, "abc" this is one valid substring and remaining 3 characters (i.e, 'a' 'b' 'c') 
outside the window will make up 3 more substring, so count = 1 + 3 = 4(From 1st window we get 4 substrings).

Similarly if we go on for every window, we get total 10 substrings.

TC: O(n), SC: O(26)
*/

/*
int numberOfSubstrings(string s) {
        int i = 0, j = 0, sub_arr_cnt = 0;
        int n = s.size();
        unordered_map<char, int> charFreq;
        while(j < n){
            charFreq[s[j]]++;
            while(charFreq['a'] >= 1 && charFreq['b'] >=1 && charFreq['c'] >= 1){
                sub_arr_cnt += n - j;
                charFreq[s[i]]--;
                i++;
            }
            j++;
        }
        return sub_arr_cnt;
    }
*/
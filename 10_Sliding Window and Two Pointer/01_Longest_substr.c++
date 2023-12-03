/*
Problem statement: Given a string s, find the length of the longest 
substring without repeating characters.
*/

/*
Approach : sliding window with Two pointer and hasharray (optimized)
1. We check if char at right index is not present in map, we will add char in map with its right index.
2. We will calculate the length, len = right - left + 1, then we will compare with previous length and consider the maximum one.
3. If char at right index is already present in map as well as char lies between range of left and right. Then, 
we will move left to previous index of char in map + 1. But, if char does not lies between range of left and right, then do nothing. That's why we need to take max of (left index and previous right index of char + 1).
4. We will simple continue the process by incrementing right by 1.
5. Once string processed return len.

TC: O(n), SC: O(n)
*/

/*
int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int left = 0, right = 0;
        int len = 0;
        while(right < s.size()){
            if(charIndex[s[right]] != -1) left = max(charIndex[s[right]] + 1, left);
            charIndex[s[right]] = right;

            len = max(right - left + 1, len);
            right++;
        }

        return len;
    }
*/
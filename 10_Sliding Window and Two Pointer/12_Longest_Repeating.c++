/*
Problem Statement: You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

/*
Approach: Sliding Window 

Initialization:
Initialize two pointers, i and j, to the beginning of the string.
Initialize maxi to 0 to keep track of the maximum frequency of any character in the current window.
Initialize longestWindow to INT_MIN, which will be updated to the length of the longest valid window.
Frequency Map:

Use an unordered map (charFreq) to keep track of the frequency of characters in the current window.
Sliding Window:

Iterate over the characters of the string using the j pointer.
Update the frequency map and maxi based on the current character.
Calculate the length of the current window (j - i + 1) and update maxi with the maximum frequency in the window.
Maintain Valid Window:

Enter a nested loop to maintain a valid window. If the length of the current window minus the maximum frequency ((j - i + 1) - maxi) is greater than k, move the i pointer to the right to shrink the window.
Update the frequency map accordingly.
Update Longest Window:

After ensuring the current window is valid, update longestWindow with the maximum of the current length and the previous longest window.
Move Right Pointer:

Move the j pointer to the right to expand the window.
Return Result:

After the iteration, return the length of the longest contiguous substring with at most k replacements.

TC: O(n), SC: O(1), as there is a constant amount of extra space used irrespective of the input size. 
*/

/*
int characterReplacement(string s, int k) {
        int i = 0, j = 0, maxi = 0;
        int longestWindow = INT_MIN;
        unordered_map<char, int> charFreq;
        while(j < s.size()){
            charFreq[s[j]]++;
            maxi = max(maxi, charFreq[s[j]]);
            while((j - i + 1) - maxi > k){
                charFreq[s[i]]--;
                i++;
            }
            longestWindow = max(longestWindow, j - i + 1);
            j++;
        }
        return longestWindow;
    }
*/
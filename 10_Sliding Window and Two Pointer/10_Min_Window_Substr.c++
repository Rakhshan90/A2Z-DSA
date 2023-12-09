/*
Problem statement: Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/

/*
Approach: Sliding Window

The given problem can be efficiently solved using the sliding window technique. Here's a step-by-step breakdown of the approach:

Check Invalid Input:

If the length of string t is greater than the length of string s, there is no possible window. Return an empty string.
Initialization:

Initialize two pointers, i and j, to the start of string s.
Initialize requiredCount to the length of string t, indicating the number of characters in t that are yet to be found in the current window.
Initialize start_i to keep track of the starting index of the minimum window found so far.
Initialize minWindowSize to INT_MAX, which will be updated to the minimum window size.
Frequency Map:

Create a frequency map (charFreq) to store the count of characters in string t.
Sliding Window:

Iterate over the characters of string s using the j pointer.
Update the frequency map and requiredCount based on the current character.
Enter a nested loop when requiredCount becomes 0, indicating that all characters from t are present in the current window.
Update Minimum Window:

Calculate the current window size (currentWindowSize) and update minWindowSize and start_i if a smaller window is found.
Move Left Pointer:

Move the i pointer to the right to shrink the window.
Update the frequency map and requiredCount based on the character at index i.
Repeat:

Repeat steps 4-6 until the end of string s is reached.
Result:

After the iteration, check if a valid window was found (minWindowSize is not INT_MAX).
Return the substring of s starting from index start_i with length minWindowSize as the result.

TC: O(n), SC: O(m)
*/

/*
string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        int i = 0, j = 0;
        int requiredCount = t.size();
        int start_i = 0;
        int minWindowSize = INT_MAX;
        unordered_map<char, int> charFreq;
        for(auto ch : t) charFreq[ch]++;

        while(j < s.size()){
            if(charFreq[s[j]] > 0) requiredCount--;

            charFreq[s[j]]--;

            while(requiredCount == 0){
                int currentWindowSize = j - i + 1;
                if(minWindowSize > currentWindowSize){
                    minWindowSize = currentWindowSize;
                    start_i = i;
                }

                charFreq[s[i]]++;
                if(charFreq[s[i]] > 0) requiredCount++;
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
*/
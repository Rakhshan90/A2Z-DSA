/*
Problem statement: You are given a string 'str' and an integer 'k' Your task is to find the length of the
largest substring with at most 'K' distinct characters.

Input: abbbbbbc, k = 2
Output: substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.
Input: abcddefg, k = 3 
Output: substrings that can be formed is [‘bcdd’, ‘cdde’, ‘ddef’]. Hence the answer is 4.
*/

/*
Approach: Sliding Window

TC : O(n), SC: O(1)
*/

/*
#include<bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    int i = 0, j = 0, count = 0;
    unordered_map<char, int> charFreq;
    while(j < str.size()){
        charFreq[str[j]]++;
        while(charFreq.size() > k){
            charFreq[str[i]]--;
            if(charFreq[str[i]] == 0) charFreq.erase(str[i]);
            i++;
        }
        count = max(count, j - i + 1); 
        j++;
    }
    return count;
}



*/
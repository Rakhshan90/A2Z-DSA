/*
Problem statement: You are given two strings 'S' and 'T'. Your task is to find the minimum
(Contiguous) substring 'W' of such that 'T' is a subsequence of 'W'. A subsequence is a sequence that can be derived from another sequence by removing zero or more elements, without changing the order. A substring is a contiguous part of a string.

Input: S = "abcdebdde", T = "bde"
Output: "bcde"

"bcde" is the substring of minimum length in which we find "bde". "bdde" is also a substring of minimum length however the index of "bcde" occurs first, therefore we returned "bcde"
*/

/*
Approach: Sliding Window
Initialization:

Initialize variables minWindow to store the length of the minimum window found so far, and window to store the actual window substring.
Initialize a variable j to 0, which will be used to track the characters in T.
Main Loop:

Iterate over each character in string S using index i.
Check for Matching Character:

If S[i] is equal to the current character in string T at index j, increment j. This is done to find the ending index of the subsequence.
Check if Subsequence Found:

If j reaches the size of string T, a subsequence has been found in the window.
Set end to the current index i to store the ending position of the subsequence.
Decrease j to get it back within bounds.
Find Starting Position of Subsequence:

Enter a loop to find the starting position of the subsequence.
If S[i] is equal to the current character in string T at index j, decrement j.
Move i left to find the starting position.
Update Minimum Window:

After finding both starting and ending positions of the subsequence, calculate the length of the current window (end - i).
If this window is smaller than the current minimum window, update minWindow and window accordingly.
Return Result:

After the main loop, return the minimum window substring stored in the window variable.

TC: O(N), SC: O(1)
*/

/*
string minWindow(string S, string T)
{
	int minWindow = INT_MAX;
    string window = "";
    int j = 0;

    for(int i = 0; i<S.size(); i++){
        if(S[i] == T[j]) j++;  //To get ending index of subsequence
        if(j == T.size()){
            int end = i; // To store end position of the subsequence
            j--;        // To make index j back to bound

            while(j >= 0){
                //TO GET THE STARTING POSITION OF THE SUBSEQUENCE
                if(S[i] == T[j]){
                    j--;
                }
                i--;    //To get starting of subsequence
            }
            //To make both index i and j back to bound
            i++;
            j++;

            if(end - i < minWindow){
                minWindow = end - i;
                window = "";

                for(int k=i; k<=end; k++){
                    window += S[k];
                }
            }
        }
    }
    return window;
}
*/
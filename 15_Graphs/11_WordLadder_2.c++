/*
Problem statement: Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:
A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
*/

/*
Approach: BFS (Levl order traversal) 
Initial configuration:
Queue: Define a queue data structure to store the level-wise formed sequences. The queue will be storing a List of strings, which will be representing the path till now. The last word in the list will be the last converted word. 
Hash set: Create a hash set to store the elements present in the word list to carry out the search and delete operations in O(1) time. 
Vector: Define a 1D vector ‘usedOnLevel’ to store the words which are currently being used for transformation on a particular level and a 2D vector ‘ans’ for storing all the shortest sequences of transformation.

The Algorithm for this problem involves the following steps:
1. Firstly, we start by creating a hash set to store all the elements present in the wordList which would make the search and delete operations faster for us to implement.
2. Next, we create a Queue data structure for storing the successive sequences/ path in the form of a vector which on transformation would lead us to the target word.
3. Now, we add the startWord to the queue as a List and also push it into the usedOnLevel vector to denote that this word is currently being used for transformation in this particular level.
4. Pop the first element out of the queue and carry out the BFS traversal, where for each word that popped out from the back of the sequence present at the top of the queue, we check for all of its characters by replacing them with ‘a’ - ‘z’ if they are present in the wordList or not. In case a word is present in the wordList, we simply first push it onto the usedOnLevel vector and do not delete it from the wordList immediately.
5. Now, push that word into the vector containing the previous sequence and add it to the queue. So we will get a new path, but we need to explore other paths as well, so pop the word out of the list to explore other paths.
6. After completion of traversal on a particular level, we can now delete all the words that were currently being used on that level from the usedOnLevel vector which ensures that these words won’t be used again in the future, as using them in the later stages will mean that it won’t be the shortest path anymore.
7. If at any point in time we find out that the last word in the sequence present at the top of the queue is equal to the target word, we simply push the sequence into the resultant vector if the resultant vector ‘ans’ is empty.
8. If the vector is not empty, we check if the current sequence length is equal to the first element added in the ans vector or not. This has to be checked because we need the shortest possible transformation sequences.
9. In case, there is no transformation sequence possible, we return an empty 2D vector.


Time Complexity and Space Complexity: It cannot be predicted for this particular algorithm because there can be multiple sequences of transformation from startWord to targetWord depending upon the example, so we cannot define a fixed range of time or space in which this program would run for all the test cases.

Note: This approach/code will give TLE when solved on the Leetcode platform due to the strict time constraints being put up there. So, you need to optimize it to a greater extent in order to pass all the test cases for LeetCode.
*/

/*
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 0;
        vector<string> usedOnThisLvl;
        usedOnThisLvl.push_back(beginWord);
        while(!q.empty()){
            vector<string> ladder = q.front();
            q.pop();
            
            if(ladder.size() > level){
                level++;
                for(auto it : usedOnThisLvl){
                    st.erase(it);
                }
                usedOnThisLvl.clear();
            }
            
            string word = ladder.back();
            if(word == endWord){
                if(ans.size() == 0) ans.push_back(ladder);
                else if(ans[0].size() == ladder.size()) ans.push_back(ladder);
            }
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        ladder.push_back(word);
                        q.push(ladder);
                        usedOnThisLvl.push_back(word);
                        ladder.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
*/

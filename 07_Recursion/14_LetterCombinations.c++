/*
Problem statement: Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

/*
Approach: "choices of picking" through recursion and backtracking
1. create mapping of phone numbers 0 to 9 with corresponding letters
2. find current number from digits of string, then find mapping of that current number from the map that you have created in step 1.
3. we will be having choices of picking one char at once for the combination. so we will use for loop to iterate over the string of words of current number. 
4. add current char to ds and make recursive call for next index i.e, findCombinations(index+1, digits, ds, ans, mp)
5. When you return from the recursive call, perform backtrack to find remaining valid combinations. 
6. Base Condition: Whenever index reaches to the size of the given digits string, store current ds in answer, and return.

TC: O(4^n), SC: ~= O(4^n). 
Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/



/*
void findCombinations(int index, string digits, string &ds, 
   vector<string> &ans, string mp[]){
       if(index>=digits.size()){
           ans.emplace_back(ds);
           return;
       }
       int num = digits[index] -'0';
       string words = mp[num];
       for(int i=0; i<words.length(); i++){
           ds.push_back(words[i]);
           findCombinations(index+1, digits, ds, ans, mp);
           //backtrack
           ds.pop_back();
       }
   }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string ds = "";
        //mapping of numbers with corresponding letters
        string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", 
        "pqrs", "tuv", "wxyz"};
        findCombinations(0, digits, ds, ans, mp);
        return ans;
    }
*/
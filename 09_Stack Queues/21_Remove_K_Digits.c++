/*
Problem statement: Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Input: "1432219", k=3
Output: "1219"

Input: "4125378", k=4
Output: "123"
*/

/*
Intuition
The basic idea is that you want to use a stack that holds values in increasing values otherwise known as a increasing monotonic stack

Approach
Opposed to using a traditional stack, I am going to use a string since it has all the operations that I would need from a stack but it would just allow me to not have to move all the elements off of a stack and put them into a string at the end.

TC: O(n), SC: O(n)
*/

/*
string removeKdigits(string num, int k) {
        string ans;
        for(auto it:num){
            while(!ans.empty() && ans.back() > it && k>0){
                ans.pop_back();
                k--;
            }

            if(!ans.empty() || it != '0') ans.push_back(it);
        }
        //edge case
        while(!ans.empty() && k>0){
            ans.pop_back();
            k--;
        }
        return ans == "" ? "0" : ans;
    }
*/
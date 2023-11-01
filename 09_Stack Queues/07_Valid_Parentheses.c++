/*
Problem statement: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Input: str = “( )[ { } ( ) ]”
Output: True

Input: str = “[ ( )”
Output: False
*/

/*
Approach: Using Stack DS
1. Whenever we get the opening bracket we will push it into the stack. I.e ‘{‘, ’[’, ’(‘.
2. Whenever we get the closing bracket we will check if the stack is non-empty or not.
3. If the stack is empty we will return false, else if it is nonempty then we will check if the
   topmost element of the stack is the opposite pair of the closing bracket or not.
4. If it is not the opposite pair of the closing bracket then return false, else move ahead.
5. After we move out of the string the stack has to be empty if it is non-empty then return it
   as invalid else it is a valid string.

TC: O(N), SC: O(N)
*/


/*
bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                // Stack is empty, no matching opening parenthesis
                if(st.empty()) return false;
                
                if( (st.top() == '(' && ch == ')') || 
                (st.top() == '{' && ch == '}') || 
                (st.top() == '[' && ch == ']') ){
                    st.pop();
                }
                else return false; // Mismatched closing parenthesis
            }
        }
 
        // If the stack is empty, all parentheses were matched
        if(st.empty()) return true;
        else return false;
}
*/
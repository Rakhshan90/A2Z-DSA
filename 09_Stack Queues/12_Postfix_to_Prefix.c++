/*
Problem statement: You are given a string denoting a valid Postfix expression containing '+',  '-', '*', '/' and lowercase letters.
Convert the given Postfix expression into an Prefix expression.

input: abc*+
output: +a*bc
*/

/*
Formula:  operator + operand 2 + operand 1
Approach 1: Using stack 
1. Scanned given expression from left to right.
2. if scanned char is operand, store it into the stack.
3. if scanned char is operator, pop 2 operands from the stack and make the result with this Formula: operator + operand 2 + operand 1.
4. Push back the result to the stack.
5. Once, given expression is exhausted, answer will be present on top of the stack.

TC: O(N), SC: O(N)
*/
/*
#include<bits/stdc++.h>
string postfixToPrefix(string &s){
    stack<string> st;
    string result;
    for(int i=0; i<s.size(); i++){
        char ch = s[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            result = ch + op2 + op1;
            st.push(result);
        }
        else st.push(string(1, ch));
    }
    return st.top();
}
*/
/*
Problem statement: You are given a string denoting a valid Prefix expression containing '+',  '-', '*', '/' and lowercase letters.
Convert the given Prefix expression into an Infix expression.

input: /-ab+-cde
output: ( (a-b) / ((c-d) + e) )
*/

/*
Intuition: Reverse the given Prefix expression before solving.
Formula: operand 1 + operator + operand 2
Approach 1: Using stack 
1. Scanned given expression from right to left.
2. if scanned char is operand, store it into the stack.
3. if scanned char is operator, pop 2 operands from the stack and perform operation on them.
4. Push back the result to the stack.
5. Once, given expression is exhausted, answer will be present on top of the stack.

TC: O(N), SC: O(N)
*/

/*
#include<bits/stdc++.h>
string prefixToInfixConversion(string &s){
	string exp;
	stack<string> st;

	for(int i=s.size()-1; i>=0; i--){
		char ch = s[i]; 
		if(ch == '+' || ch == '-' || ch == '/' || ch == '*'){
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();

			exp = "(" + op1 + ch + op2 + ")";
			st.push(exp);
		}
		else st.push(string(1, ch));
	}
	return st.top();
}
*/
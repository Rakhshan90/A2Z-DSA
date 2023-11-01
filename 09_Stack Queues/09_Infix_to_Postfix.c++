/*
Problem statement: You are given a string 'exp' which is a valid infix
expression. Convert the given infix expression to postfix expression.

Expression contains digits, lower case English letters, (, ), +, -, *, /, and ^.

Examples:
(A + B) * (C - D) -> AB+CD-*
(A + B) / (C - D) - (E * F) -> AB+CD-/EF*-

*/

/*
Approach 1: Using stack
1. If scanned char is lower-case english letters, or digits, concatenate it to the answer
string.
2. If scanned char is '(' , push it into the stack.
3. If scanned char is ')' , pop from the stack and concatenate to answer string
until '(' is found. Once you get '(' on top of the stack, pop it from the stack.
4. If scanned char is operator with lower precedence than the operator on top of the stack, pop from the stack and concatenate to answer string until you get operator with lower precedence.
5. push the scanned operator into stack.
6. Once you scanned all the chars of given string, but still stack isn't empty, then pop char from stack and concatenate to answer string.
7. return the answer string.

TC: O(N), SC: O(N)
*/

/*
#include<bits/stdc++.h>
int prec(char ch){
	if(ch == '^') return 3;
	else if(ch == '/' || ch == '*') return 2;
	else if(ch == '+' || ch == '-') return 1;
	else return -1;
}

string infixToPostfix(string exp){
	stack<char>st;
	string ans;
	for(int i=0; i<exp.size(); i++){
		char ch = exp[i];

		if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) ans+=ch;
		else if(ch == '(') st.push(ch);
		else if(ch == ')'){
			while(st.top() != '('){
				ans+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && prec(exp[i]) <= prec(st.top())){
				ans+=st.top();
				st.pop();
			}
			st.push(ch);
		}
	}

	while(!st.empty()){
		ans+=st.top();
		st.pop();
	}

	return ans;
}
*/
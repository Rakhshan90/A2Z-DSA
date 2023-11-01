/*
Problem statement: You are given a string denoting a valid Postfix expression containing '+',  '-', '*', '/' ,lowercase letters and uppercase letters.
Convert the given Postfix expression into an Infix expression.

input: ab+c+
output: ((a+b) + c)
*/

/*
Approach: Using stack
Same approach as we use in Prefix to Infix conversion except the following things
1. Traverse the given Postfix expression into forward direction.
2. Formula: ( + operand2 + operator + operand1 + )

TC: O(N), SC: O(N)
*/

/*
string postToInfix(string postfix) {
    string result;
	stack<string> st;

	for(int i=0; i<postfix.size(); i++){
		char ch = postfix[i]; 
		if(ch == '+' || ch == '-' || ch == '/' || ch == '*'){
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();

			result = "(" + op2 + ch + op1 + ")";
			st.push(result);
		}
		else st.push(string(1, ch));
	}
	return st.top();
}
*/
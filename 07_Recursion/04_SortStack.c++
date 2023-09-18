//sort stack in decreasing order using recursion
/*
Approach : Using Recursion
1. We will keep aside elements form the top of the stack until stack is empty(base case)
2. Once stack is empty, we will be returning from the recursive calls so insert those aside values in the sorted decreasing order in stack.
3. Logic of Sorted decreasing order: We will keep aside elements form the top of the stack until base case reached. 
4. Base case logic: As we know we have to keep bigger value at stack top, so if stack is empty, don't do anything just insert it, but if stack isn't empty, we will check if stack.top <= val then all good, just insert it. 
5. When you return from the recursive call, insert those aside values in the stack.

TC: O(N^2), SC: O(N)
*/

/*
#include <bits/stdc++.h> 
void insert(stack<int> &stack, int val){
    if(stack.empty() || (!stack.empty() && stack.top() <= val)){
        stack.push(val);
        return;
    }
    int top = stack.top();
    stack.pop();
    insert(stack, val);
    stack.push(top);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;
    
    int top = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, top);
}
*/
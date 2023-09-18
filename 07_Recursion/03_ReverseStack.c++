//Reverse stack using recursion
/*
Approach : Using recursion and insert at bottom logic
1. We will keep aside elements form the top of the stack until stack is empty(base case)
2. Once stack is empty, we will be returning from the recursive calls so insert those aside values in the bottom of the stack.

TC: O(N^2), SC: O(N)
*/


/*
void insertAtBottom(stack<int> &stack, int val){
    if(stack.empty()){
        stack.push(val);
        return;
    }
    int top = stack.top();
    stack.pop();
    insertAtBottom(stack, val);
    stack.push(top);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, top);
}
*/
/*
Problem statement: Implement queue using stack. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty). 
*/

/*
Approach 1: Using two stacks where push operation is O(N)
1. Add elements to s2 from s1
2. Add elements back to s1 from s2
3. After step 2, stack s1 becomes queue. 

TC: O(N), SC: O(2N)
*/

/*
class MyQueue {
public:
    stack<int>s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }    
    }
    
    int pop() {
        if(s1.empty()) return -1;
        else {
            int front = s1.top();
            s1.pop();
            return front;
        }
    }
    
    int peek() {
        if(s1.empty()) return -1;
        else return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
*/

/*
Approach 2: Using two stacks where push operation is O(1)
1. push(): Add elements to input stack.
2. pop(): if output stack is empty, shift all elements from input stack to output stack, then 
remove top element from the output stack. If output stack is already filled, don't need to 
shift elements from input stack to output stack.
3. peek(): if output stack is empty, shift all elements from input stack to output stack, then return top element of the output stack. if output stack is already filled, don't need to shift elements from input stack to output stack.
4. empty(): if either input stack or output stack is not empty then queue is not empty.

TC: pop() -> pop can be 0(1) or O(n) .
0(1) when all elements are already shifted . So we just need to delete the element . So here we can say that time complexity can
be 0(1 ) or amortised O(1).
Same for peek().
SC: O(2N)
*/

/*
class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};
*/


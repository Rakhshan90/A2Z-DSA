/*
Problem statement: Implement stack using queue. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
*/

/*
Approach 1: Using two queues
1. Add element to q2.
2. While q1 is not empty, transfer each elements from q1 to q2 one by one.
3. Swap each values from q2 to q1.
4. After step 3, q1 will become stack so you can implement remaining operations of stack by keeping in mind that q1 is stack.

TC: O(N), SC: O(N)
*/

/*
class MyStack {
public:
    queue<int>q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        if(q1.empty()) return -1;
        else{
            int top = q1.front();
            q1.pop();
            return top;
        }
    }
    
    int top() {
        if(q1.empty()) return -1;
        else return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
*/

/*
Approach 2: Using only one queue
1. Add element to queue.
2. While size of the queue is greater than 1. Remove element from the front of the queue and Add it to the queue and reduce the size of the queue by 1. 
3. Repeat step 2 until queue size becomes equal to 1. After that queue is converted into stack.

TC: O(N), SC: O(N)
*/

/*
class MyStack {
public:
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int n = q1.size();
        while(n > 1){
            q1.push(q1.front());
            q1.pop();
            n--;
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        else{
            int top = q1.front();
            q1.pop();
            return top;
        }
    }
    
    int top() {
        if(q1.empty()) return -1;
        else return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
*/
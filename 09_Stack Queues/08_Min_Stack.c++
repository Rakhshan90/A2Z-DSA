/*
Problem statement: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*/

/*
Approach 1: Using pairs to store the value and minimum element till now. 
1. The first element in the pair will store the value and the second element will store the minimum element till now.
2. When the first push operation comes in we will push the value and store it as minimum itself in the pair. 
3. In the second push operation, we will check if the top element’s minimum is less than the new value. If it is then we will push the value with minimum as the previous top’s minimum. To get the getMin element to take the top’s second element.

TC: O(1), SC: O(2N)
*/

/*
class MinStack {
public:
    stack<pair<int, int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push(make_pair(val, val));
        else{
            int mini = st.top().second;
            mini = min(mini, val);
            st.push(make_pair(val, mini));
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        else return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
*/


/*
Approach 2:
1. If new value is smaller than min we will push a modified value which is a push(2 * Val – min) into the stack and will update min to the value of the original number. If it’s not then we will just push it as it is.
2. While making pop we will check if the top value is lesser than min, If it is then we must update our min to its previous value. In order to do that min = (2 * min) – (modified value) and we will pop the element.
3. While returning the top value we know that it is a modified value. We will check if the top value is lesser than min, If it is then we will return the min as the top value.
4. We will just return the value of min.

TC: O(1), SC: O(N)
*/

/*
class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val < mini){
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() < mini) mini = 2 * mini - st.top();
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
       
        if(st.top() < mini) return mini;
        else return st.top();
    }
    
    int getMin() {
        return mini;
    }
};
*/
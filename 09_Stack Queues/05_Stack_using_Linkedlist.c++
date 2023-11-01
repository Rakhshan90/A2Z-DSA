/*
Problem statement: You must implement the Stack data structure using a Singly
Linked List.
Create a class named 'Stack' which supports the following
operations(all in 0(1) time):
*/

/*
Intuition: We can assume our linked list to be a horizontal stack where the operations like deletion and insertion would take place at the top of the stack or at the head of the linked list.

Approach: 

Push(): Pushing the element at the top of the stack would mean the same as pushing an element at the beginning of the linked list.  

pop(): Removing an element from the top of the stack is the same as removing the element from the beginning of our linked list.

size(): returns the size of the stack
For this, we maintain a size variable. After each push operation, we increment the size variable and after each pop operation, we decrement the size variable.

isEmpty(): return true, if top is nullptr, otherwise return false

getTop(): return -1 if top is nullptr, otherwise return top->data which will be top of our stack

TC: O(1), SC: O(1)
*/

/*
class Stack
{
    //Write your code here

public:
    Node*top;
    int size;
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if(top == nullptr) return true;
        else return false;
    }

    void push(int data)
    {
        Node*newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop()
    {
        if(top == nullptr) return;
        Node*temp = top;
        top = top->next;
        temp->next = nullptr;
        delete temp;
        size--;
    }

    int getTop()
    {
        if(top == nullptr) return -1;
        return top->data;
    }
};
*/
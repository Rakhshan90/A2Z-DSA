/*
Problem statement: You are given 'q' queries, where each query can be of the
following types: 
query 1: Push the element 'x' in the queue.
query 2: Pop the front element of the queue and returning it. If there's no element in the
queue return -1.

Your task is to implement a queue using LinkedList that supports these two queries.
You must write an algorithm whose time complexity is 0(1), and
whose space complexity is 0(1).
*/

/*
Intuition: We can assume our linked list to be a horizontal queue where the operations like deletion would take place at the front of the queue or at the head of the linked list and 
insertion would take place at the rear of the queue or at the tail of the linked list.

Approach: 
enqueue(): Pushing the element at the rear of the queue would mean the same as pushing an element at the end of the linked list.

dequeue(): Removing the element at the front of the queue would mean the same as removing an element at the beginning of the linked list.

TC: O(1), SC: O(1)
*/

/*
void Queue::push(int x) {
    Node*newNode = new Node(x);
    if(newNode == NULL) return; //overflow
    else{
        if(front == NULL) front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int Queue::pop() {
    if(front == NULL) return -1;
    else{
        Node*temp = front;
        int rm = front->data;
        front = front->next;
        temp->next = NULL;
        delete temp;
        return rm;
    }
}
*/
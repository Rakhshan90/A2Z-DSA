/*
You're given a positive integer represented in the form of a singly linked-list of digits. The length of the number is 'n'. Add 1 to the number, i.e., increment the given number by one.
The digits are stored such that the most significant digit is at the head of the linked list and the least significant digit is at the tail of the linked list.

ex: input: 1->5->2 
   output: 1->5->3

ex: input: 9->9
   output: 1->0->0
*/

/*
Approach: 
step 1 : reverse the given linked list 
step 2 : increment curr's data by 1
step 3 : find digit to replace curr's node with digit and add remaining carry to next node. 
Repeat step 3 unitl curr's next is nullptr and carry!=0 
step 4: When we exit the loop we will be at last node and if carry is remains then make a node of remaining carry and insert it into last of the list
step 5: reverse the modified list again to get the final answer

TC: O(n), SC: O(1)
*/


/*
Node*reverse(Node*&ansHead){
    Node*pre=nullptr;
    Node*curr=ansHead;
    Node*forward=nullptr;
    while(curr){
        forward=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forward;
    }
    return pre;
}
Node *addOne(Node *head)
{   
    //step 1 : reverse the given linked list
    head = reverse(head);

    //step 2 : increment curr's data by 1
    Node*curr = head;
    int sum = curr->data + 1;

    //step 3 : find digit to replace curr's node with digit and add remaining carry to next node
    int carry = 0;
    int digit = sum%10;
    carry = sum/10;
    curr->data = digit;
    while(curr->next && carry!=0){
        curr=curr->next;
        sum = curr->data + carry;
        digit = sum%10;
        carry = sum/10;
        curr->data = digit;
    }
    //step 4: make node of remaining carry and insert it into last of list
    if(curr->next==nullptr && carry!=0){
        Node*newNode = new Node(carry);
        curr->next = newNode;
    }

    //step 5 : reverse the final answer
    head = reverse(head);
    return head;

}
*/
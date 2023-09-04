/*
You are given a Singly Linked List of integers. You have to return
true if the linked list is palindrome, else return false.
A Linked List is a palindrome if it reads the same from left to right
and from right to left.
*/

/*
Approach 1: Convert the linked list into array and apply the two pointer appraoch.
*/

/*
Approach 2: 
step 1. Find the middle of the linkedList
step 2. Divide given linkedList into two equal halves
step 3. reverse the right half of linkedList
step 4. Compare both halves return false if at any point they are not same else return true
step 5. Don't forgot to revert the changes back in step 3 before returning answer
*/

/*

Node*middle(Node*&head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    //middle node
    return slow;

}
Node*reverse(Node*&head){
    Node*pre=NULL;
    Node*curr=head;
    Node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forward;
    }
    return pre;
}
bool isPalindrome(Node *head)
{
    //step 1. Find the middle of the linkedList
    Node* mid = middle(head);

    //step 2. Divide given linkedList into two equal halves
    Node*right=mid->next;
    mid->next=NULL;

    //step 3. reverse the right half of linkedList
    right=reverse(right);

    //step 4. Compare both halves return false if at any point they are not same else return true
    Node*curr=head;
    while(curr!=NULL && right!=NULL){
        if(curr->data!=right->data) return false;
        curr=curr->next;
        right=right->next;
    }
    //revert the changes back
    right=reverse(right);
    return true;

}

*/
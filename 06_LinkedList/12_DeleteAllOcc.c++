/*
You're given a doubly-linked list and a key 'k'. Delete all the nodes having data equal to 'k'.
*/

/*
Approach : Intuition of this appraoch is to skip all the occurrences instead of deleting 
1. check if curr node's data is equal to the key and if curr node is head node then update the head
2. check if curr node's data is equal to the key and if curr node is not head then simply skip that node 

TC: O(n), SC: O(1)
*/
/*
Node * deleteAllOccurrences(Node* head, int k) {
    Node*curr=head;
    while(curr){
        if(curr->data==k && curr==head) head=head->next;
        else if(curr->data==k) curr->prev->next = curr->next;
        curr=curr->next;
    }
    return head;
}
*/
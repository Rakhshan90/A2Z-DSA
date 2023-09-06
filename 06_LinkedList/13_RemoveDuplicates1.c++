/*
You are given a sorted doubly linked list of size 'n'.
Remove all the duplicate nodes present in the linked list.
*/

/*
Approach: since list is sorted duplicate nodes will be present at adjacent places
1. Check if curr's node data is equal to curr's next node data then remove curr's next node but before detetion keep track of curr's next next node.
2. else move curr by step one.

TC:O(n), SC:O(1)
*/

/*
Node * removeDuplicates(Node *head)
{
    Node*curr=head;
    while(curr){
        if(curr->next && curr->data==curr->next->data){
            Node*next_next = curr->next->next;
            Node*toBeDeleted = curr->next;
            delete(toBeDeleted);
            curr->next = next_next;
        }
        else curr=curr->next;
    }
    return head;
}

*/
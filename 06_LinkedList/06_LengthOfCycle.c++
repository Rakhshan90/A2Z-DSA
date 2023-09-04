/*
You're given a linked list. The last node might point to null, or it might point to a node in the list, thus forming a cycle.
Find out whether the linked list has a cycle or not, and the length of the cycle if it does.
If there is no cycle, return O, otherwise return the length of the cycle.
*/

/*
Approach: 1. Find out the starting node of the cycle in the linked list
          2. If starting node does not exist, return 0
          3. If starting node does exist, start traversing the cycle and increment the length by 1
          4. return the length of the cycle.
*/



/*
Node *firstNode(Node *head)
{
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) break;
    }
    if(fast==NULL || fast->next==NULL) return NULL;

    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
int lengthOfLoop(Node *head) {
    int length=1;
    Node* startOfLoop = firstNode(head);
    Node*curr=startOfLoop;
    if(startOfLoop){
        //cycle exist, find lenght of it
        while(curr->next!=startOfLoop){
            length++;
            curr=curr->next;
        }
        return length;
    }
    else{
        return 0;
    }
}

*/
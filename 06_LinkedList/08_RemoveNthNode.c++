/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

/*
Approach: 
1. Get the length of the linked list using the length() function.
2. Calculate the position of the node to remove, which is len - n.
3. Create two pointers, pre and curr. pre will point to the node before the node to remove, and curr will point to the node to remove.
4. Iterate position times. In each iteration, move pre forward one node. This will bring pre to the node before the node to remove. Set curr to curr's next node.
5. If pre is not NULL, then set pre's next node to curr's next node. Otherwise, the first node is being removed, so set the head of the linked list to curr's next node.
6. Set curr's next node to NULL and delete curr.
7. Return the head of the linked list.

TC: O(n), SC: O(1)
*/


/*
int length(ListNode* &head){
        ListNode*curr=head;
        int len=0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        int len = length(head);
        int position = len-n;
        ListNode*pre=NULL;
        ListNode*curr=head;
        int i=0;
        while(i<position && curr!=NULL){
            pre=curr;
            curr=curr->next;
            i++;
        }
        if (pre == NULL) {
            // If pre is still NULL, it means we are removing the first node
            head = curr->next;
        } else {
            pre->next = curr->next;
        }
        curr->next=NULL;
        delete curr;
        return head;
    }
*/


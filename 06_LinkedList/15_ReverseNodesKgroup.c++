/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/


/*
Appraoch 1: By using recursion (Better approach)
1. Find the length of the given linked list
2. if length < k, base case reached return head.
3. reverse first k group via iteratively
4. we have to reverse remaining k gorup via recursively until len<k. 
   1. after step 3 our head just point before the nex.
   2. After step 3 our nex point to the node where further reversing takes place so, nex serve as head for recursive call. 
   3. since head just before the nex, Therefore recursive call will be
   head->next = recursion(nex). but before making call make sure nex should be exist.
   4. substract k gorup from length as you reversing k gorup.
5. retur the prev as head of the modified list.


TC:O(n), SC:O(k) due recursive call stored in recursion stack.
*/

/*
int length(ListNode*&head){
        int cnt=0;
        ListNode*curr=head;
        while(curr){
            curr=curr->next;
            cnt++;
        }
        return cnt;
    }
    ListNode*reverseList(ListNode*&head, int k, int len){
        //base case
        if(len<k) return head;
        //step 1: reverse first k group via iteratively
        ListNode*prev=nullptr;
        ListNode*curr=head;
        ListNode*nex=nullptr;
        int i=0;
        while(curr && i<k){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            i++;
        }

        //step 2: reverse remaining k gorup via recursively until len<k
        if(nex){
            head->next = reverseList(nex, k, len-k);
        }
        //new head of the list
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        return reverseList(head, k, len);
    }
*/


/*
Approach 2: Optimal approach (iteratively)
1. Create a dummy node. Point next to this node to head of the linked list provided.
2. Iterate through the given linked list to get the length of the list.
3. Create three pointer pre,cur and nex to reverse each group.
4. Iterate through the linked list until the length of list to be processed is greater than and equal to given k.
5. For each iteration, point cur to pre->next and nex to cur->next.
6. Start nested iteration for length of k.
7. For each iteration, modify links as following steps:-
cur->next = nex->next
nex->next = pre->next
pre->next = nex
nex = cur->next
Move pre to cur which is the last node of reversed list and reduce length by k.


TC: O(N)
Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).
Space Complexity: O(1)
*/

/*
ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;
        ListNode*pre = dummy;
        ListNode*curr = dummy;
        ListNode*nex = dummy;
        //find the length of given list
        int cnt=0;
        while(curr->next){
            curr=curr->next;
            cnt++;
        }

        while(cnt>=k){
            curr=pre->next;
            nex=curr->next;
            //perform k-1 operation
            for(int i=1; i<k; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            cnt-=k;
            pre=curr;
        }
        return dummy->next;
    }
*/
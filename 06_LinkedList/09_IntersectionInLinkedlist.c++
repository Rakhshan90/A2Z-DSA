/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

/*
Approach 1 : Brute force  TC: O(m*n), SC: O(1) 
1. Keep any one of the list to check its node present in the other list. Here, we are choosing the first list for this task.
2. Iterate through the other list. Here, it is the second one. 
3. Check if the both nodes are the same. If yes, we got our first intersection node.
4. If not, continue iteration.
5. If we did not find an intersection node and completed the entire iteration of the first list, then there is no intersection between the provided lists. Hence, return null.
*/

/*
Approach 2 : Using Hashing - unordered_set<node*> (Better approach)
TC: O(m+n), SC: O(m) 
1. Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
2. Iterate through list 2 and search the hashed value in the hash table. If found, return node.
*/
/*
node* intersectionPresent(node* head1,node* head2) {
    unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}
*/

/*
Approach 3 : Optimised approach TC: O(2*max(length of list1,length of list2)), SC: O(1) 
1. Take two dummy nodes for each list. Point each to the head of the lists.
Iterate over them. 
2. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.
*/

/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*curr1=headA;
        ListNode*curr2=headB;
        while(curr1!=curr2){
            curr1 = curr1 == nullptr? headB : curr1=curr1->next;
            curr2 = curr2 == nullptr? headA : curr2=curr2->next;
        }
        if(curr1==curr2) return curr1;
        else return nullptr;
    }
*/



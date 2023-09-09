/*
Given the head of a linked list, rotate the list to the right by k places.
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/

/*
Approach: 
Let’s take an example. 

head = [1,2,3,4,5] k = 2000000000

If we see a brute force approach, it will take O(5*2000000000) which is not a good time complexity when we can optimize it.

We can see that for every k which is multiple of the length of the list, we get back the original list. Try to operate brute force on any linked list for k as a multiple of the length of the list.

This gives us a hint that for k greater than the length of the list, we have to rotate the list for k%length of the list. This reduces our time complexity.

Steps to the algorithm:-

1. Calculate the length of the list.
2. Connect the last node to the first node, converting it to a circular linked list.
3. Find number of effective ratation, then subtract it from the length of the list.
4. Move curr until k becomes 0. You will find that curr's next points to the new head of the modified list. 
5. Update the head with curr's next and then point curr's next to null to cut the link of circular list.


TC: O(length of list) + O(length of list – (length of list%k)), SC: O(1)
*/


/*
ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(!head || !head->next || k==0) return head;

        int l=1;
        ListNode*curr=head;
        while(curr->next){
            curr=curr->next;
            l++;
        }
        curr->next=head;
        //find number of effective ratation
        k = k % l;
        k = l - k;
        while(k--) curr=curr->next;
        //update head
        head=curr->next;
        curr->next=nullptr;

        return head;
    }
*/
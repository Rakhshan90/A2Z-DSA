/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/*
TC: O(m+n), SC: O(1)
/*
void insert(ListNode* &ansHead, ListNode* &ansTail, int d){
        ListNode*newNode = new ListNode(d);
        if(!ansHead){
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //prepare ans list
        ListNode*ansHead = nullptr;
        ListNode*ansTail = nullptr;

        int carry=0;
        int sum=0;
        int digit;
        ListNode*curr1=l1;
        ListNode*curr2=l2;
        while(curr1 || curr2){
            int val1=0;
            int val2=0;
            if(curr1) {
               val1=curr1->val; 
               curr1=curr1->next;
            }
            if(curr2){
                val2=curr2->val;
                curr2=curr2->next;
            }
            sum = val1 + val2 + carry;
            digit = sum%10;
            carry = sum/10;
            insert(ansHead, ansTail, digit);
        }
        while(carry!=0){
            sum = carry;
            digit = sum%10;
            carry = sum/10;
            insert(ansHead, ansTail, digit);
        }
        return ansHead;
    }
*/
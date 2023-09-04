//Delete Node in a Linked List
/*
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
*/

/*
Approach: The intuition behind this approach is to simulate the deletion operation without actually removing the node from memory. By copying the value of the next node into the current node, we effectively "replace" the value of the given node. Then, by updating the next pointer of the current node to skip the next node, we "remove" the next node from the linked list.

TC: O(1), SC:O(1)
*/

/*
class Solution {
public:
    void deleteNode(ListNode* node) {
        //copy the value of next node to the given node that needs to be deleted.
        node->val = node->next->val;
        //now we have two duplicate values. so, skip the next node
        node->next = node->next->next;
    }
};
*/
/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.
*/

/*
Approach : Since each list, followed by the bottom pointer, are in sorted order. Our main aim is to make a single list in sorted order of all nodes. So, we can think of a merge algorithm of merge sort.

1. We will recurse until the head pointer moves null. The main motive is to merge each list from the last.
2. Merge each list chosen using the merge algorithm. The steps are
3. Create a dummy node. Point two pointers, i.e, temp and res on dummy node. res is to keep track of dummy node and temp pointer is to move ahead as we build the flattened list.
4. We iterate through the two chosen. Move head from any of the chosen lists ahead whose current pointed node is smaller. 
5. Return the new flattened list found.

TC: O(n), SC: O(1)

*/


/*
Node*mergeTwoList(Node*l1, Node*l2){
	Node*dummy = new Node(-1);
	Node*temp = dummy;

	while(l1 && l2){
		if(l1->data < l2->data){
			temp->bottom = l1;
			temp=temp->bottom;
			l1=l1->bottom;
		}
		else{
			temp->bottom = l2;
			temp=temp->bottom;
			l2=l2->bottom;
		}
	}
	
	if(l1) temp->bottom = l1;
	if(l2) temp->bottom = l2;

	return dummy->bottom;
	
}
Node *flatten(Node *root)
{
   if(!root || !root->next) return root;
	
	root->next = flatten(root->next);

	//merge both the lists
	root = mergeTwoList(root, root->next);
	return root;
}
*/
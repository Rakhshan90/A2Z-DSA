//Reverse a doubly linked list
/*
Approach: 1. swap the next and prev pointers for each node.
*/

/*

Node* reverseDLL(Node* head)
{   
    Node*pre=NULL;
    Node*curr=head;
    Node*forwrd=NULL;
    while(curr!=NULL){
        forwrd=curr->next;
        curr->next=curr->prev;
        curr->prev=forwrd;
        pre=curr; 
        curr=forwrd;
    }  
    return pre;
}


*/
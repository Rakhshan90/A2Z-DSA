/*
Node* middle(Node*&head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node*merge(Node*&left, Node*&right){
    //dummy node
    Node*dummy=new Node(-1);
    Node*temp=dummy;
    if(left==nullptr) temp->next=right;
    if(right==nullptr) temp->next=left;

    while(left!=nullptr && right!=nullptr){
        if(left->data<=right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=nullptr){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=nullptr){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return dummy=dummy->next;
}
Node* sortList(Node* head){
    //base case
    if(head==nullptr || head->next==nullptr) return head;
    Node* mid=middle(head);
    Node*right=mid->next;
    mid->next=nullptr;
    Node*left=head;

    left=sortList(left);
    right=sortList(right);

    //merge 
    Node*result=merge(left, right);
    return result;
}
*/
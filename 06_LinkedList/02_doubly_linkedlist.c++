#include<iostream>

using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};
void insertAtHead(node *&head, int d){
    node*temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(node *&tail, int d){
    node*temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtPosition(node *&head, node *&tail, int position, int d){
    if(position==1){
        insertAtHead(head, d);
        return;
    }
    else{
        node*ptr = head;
        int i=1;
        while(i<position-1){
            ptr=ptr->next;
            i++;
        }
        //inserting at tail
        if(ptr->next==NULL){
            insertAtTail(tail, d);
            return;
        }
        //inserting at position
        node*temp = new node(d);

        temp->next = ptr->next;
        ptr->next->prev = temp;  // prev and next connection
        ptr->next = temp;       //insert
        temp->prev = ptr;
    }
}
void deleteNode(node *&head, node *&tail, int position){
    if(position==1){
        node*ptr=head;
        ptr->next->prev = NULL;
        head=ptr->next;
        //now free krdo memory ptr ki
        ptr->next = NULL;
        
        delete ptr;
    }
    else{
        node*pre = NULL;
        node*current = head;
        int i=1;
        while(i<position){
            pre = current;
            current = current->next;
            i++;
        }
        current->prev = NULL;
        pre->next = current->next;
        // pre->prev = current->prev;
        current->next = NULL;
        delete current;

        //homework done
        if(pre->next == NULL){
            tail = pre;
        }
    }
}
void forward(node*head){
    node*ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void backward(node*&tail){
    node*ptr = tail;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr ->prev;
    }
    cout<<endl;
}
int length(node*head){
    int len = 0;
    node*ptr = head;
    while(ptr!=NULL){
        len++;
        ptr = ptr->next;
    }
    return len;
}
int main(){
    node*node1 = new node(5);
    node*head = node1;
    node*tail = node1;
    // forward(head);
    backward(tail);
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    insertAtHead(head, 2);
    // insertAtHead(head, 4);
    // insertAtHead(head, 1);
    insertAtTail(tail, 4);
    insertAtTail(tail, 6);
    insertAtPosition(head, tail, 4, 10);
    forward(head);
    backward(tail);
    deleteNode(head, tail, 3);
    forward(head);
    backward(tail);
    // cout<<"Length: "<<length(head)<<endl;
    // cout<<"head: "<<head->data<<endl;
    // cout<<"tail: "<<tail->data<<endl;
    return 0;
}
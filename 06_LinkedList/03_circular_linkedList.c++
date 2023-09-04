#include<iostream>

using namespace std;
class node{
    public:
    int data;
    node*next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};
void insert(node* &tail, int element, int d){
    //empty list 
    if(tail == NULL){
        node*temp = new node(d);
        tail = temp;
        temp->next = temp;
    }
    //non-empty list 
    else{
        node*current = tail;
        while(current->data!=element){
            current=current->next;
        }
        //now current reached out to that element
        node*temp = new node(d);
        temp->next = current->next;
        current->next = temp;
    }
}
void deleteNode(node* &tail, int value){
    //empty list
    if(tail==NULL){
        return;
    }
    else{ 
    //non-empty list
    node*prev = tail;
    node*current = prev->next;
    while(current->data!=value){
        prev = current;
        current = current->next;
    }
    //now current reached out to that value
    prev->next = current->next;
    // for 1 node 
    if(current==prev){
        tail = NULL;      //updating tail 
    }
    //for >=2 node
    else if(tail == current){
        tail = prev;      //updating tail
    }
    current->next = NULL;
    delete current;
    }
}
void print(node *tail){
    node*ptr = tail;
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail!=ptr);
    cout<<endl;
}
bool check(node*tail){
    //for empty linkedlist
    if(tail==NULL){
        return true;
    }
    //for 1 and more than 1 node
    node*temp=tail->next;
    while(temp!=NULL && temp!=tail){
        temp=temp->next;
    }
    if(temp==tail)
    return true;
    else
    return false;

}
int main(){
    node*tail = NULL;

    insert(tail, 0, 5);
    print(tail);

    insert(tail, 5, 8);
    print(tail);

    insert(tail, 8, 2);
    print(tail);

    insert(tail, 5, 4);
    print(tail);

    insert(tail, 8, 3);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    if(check(tail)){
        cout<<"LinkedList is circular in nature"<<endl;
    }
    else{
        cout<<"LinkedList is not circular"<<endl;
    }

    return 0;
}
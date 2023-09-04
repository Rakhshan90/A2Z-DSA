#include <iostream>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
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
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    // tail = tail->next;
    tail = temp;
}
void insertAtPosition(node *&head, node *&tail, int position, int d)
{
    // insert at first position
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    node *ptr = head;
    int i = 1;
    while (i < position - 1)
    {
        ptr = ptr->next;
        i++;
    }
    // insert at last position
    if (ptr->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    node *temp = new node(d);
    temp->next = ptr->next;
    ptr->next = temp;
}
void deleteNode(node *&head, node *&tail, int position)
{
    if (position == 1)
    {
        node *ptr = head;
        head = head->next;
        // now free krdo memory ptr ki
        ptr->next = NULL;
        delete ptr;
    }
    else
    {
        node *prev = NULL;
        node *current = head;
        int i = 1;
        while (i < position)
        {
            prev = current;
            current = current->next;
            i++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;

        // homework done
        if (prev->next == NULL)
        {
            tail = prev;
        }
    }
}
void deleteNodeWithValue(node *&head, int val)
{
    node *prev = head;
    node *current = head->next;
    while (current->data != val && current->next != NULL)
    {
        prev = prev->next;
        current = current->next;
    }
    if (current->data == val)
    {
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}
// Detecting cycle in linkedList by using map
// bool check(node *&head)
// {
//     // empty linkedList
//     if (head == NULL)
//         return false;
//     // for non-empty linkedList
//     map<node *, bool> visited;
//     node *ptr = head;
//     while (ptr != NULL)
//     {
//         // if cycle is present
//         if (visited[ptr] == true)
//         {
//             return true;
//         }
//         else
//         {
//             visited[ptr] = true;
//             ptr = ptr->next;
//         }
//     }
//     // if ptr reaches NULL
//     return false;
// }
// Detecting cycle in linkedList by using floyd's cycle detection algorithm
// node*floydDetection(node *&head)
// {
//     node *fast = head;
//     node *slow = head;
//     while (fast != NULL)
//     {
//         fast = fast->next;
//         if (fast != NULL)
//         {
//             fast = fast->next;
//         }
//         slow = slow->next;

//         if (fast == slow)
//         {
//             return slow;
//         }
//     }
//     // if fast reaches NULL
//     return NULL;
// }

//beginning/start node of loop in LL
// node*getStartingNode(node *&head){
//     if(head==NULL){
//         return NULL;
//     }
//     node*intersectionPoint = floydDetection(head);
//     if(intersectionPoint==NULL){
//         return NULL;
//     }
//     node*slow = head;
//     while(slow!=intersectionPoint){
//         slow = slow->next;
//         intersectionPoint=intersectionPoint->next;
//     }
//     return slow;

// }
// node*remove(node *&head){
//     if(head==NULL){
//         return NULL;
//     }
//     node*startOfLoop = getStartingNode(head);
//     if(startOfLoop==NULL){
//         return head;
//     }
//     node*ptr = startOfLoop;
//     while(ptr->next!=startOfLoop){
//         ptr=ptr->next;
//     }
//     ptr->next=NULL;
//     return head;
// }
void print(node *&head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(1);
    node *head = node1;
    node *tail = node1;
    print(head);
    insertAtHead(head, 5);
    insertAtTail(tail, 7);
    insertAtTail(tail, 3);
    insertAtPosition(head, tail, 4, 10);
    print(head);
    // to verify
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    deleteNode(head, tail, 1);
    deleteNodeWithValue(head, 7);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    // for creating a cycle
    // tail->next = head->next;

    // if (check(head))
    //     cout << "cycle is present";
    // else
    //     cout << "cycle is not present";
    // if (floydDetection(head))
    // {
    //     cout << "cycle is present"<<endl;
    // }
    // else
    //     cout << "cycle is not present"<<endl;
    // node*ans = getStartingNode(head);
    // cout<<"First node of loop in LL is: "<<ans->data<<endl;

    // remove(head);
    // print(head);
    // if (floydDetection(head))
    // {
    //     cout << "cycle is present"<<endl;
    // }
    // else
    //     cout << "cycle is not present"<<endl;
    return 0;
}
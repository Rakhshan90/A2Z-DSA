/*
Problem statement: A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
*/

/*
Approach 1: By using unordered_map and clone list
1. Create a copy list form the original list
2. Create mapping of the original list
3. Copy the random pointers of the original list to the copied list
4. Once everything is copied, return the head of the copied list

TC: O(N), SC: O(N)
*/
/*
void insert(Node*&copyHead, Node*&copyTail, int d){
        Node*newNode = new Node(d);
        if(!copyHead){
            copyHead=newNode;
            copyTail=newNode;
        }
        else{
            copyTail->next=newNode;
            copyTail=newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        //step 1: create a copy list
        Node*copyHead=nullptr;
        Node*copyTail=nullptr;
        Node*curr=head;
        while(curr){
            insert(copyHead, copyTail, curr->val);
            curr = curr->next;
        }

        //step 2:  mapping of original list
        Node*copyPtr=copyHead;
        Node*ogPtr=head;
        while(ogPtr){
            mp[ogPtr] = copyPtr;
            ogPtr=ogPtr->next;
            copyPtr=copyPtr->next;
        }

        //step 3: Copy random pointers of original list to copy list
        ogPtr=head;
        copyPtr=copyHead;
        while(ogPtr){
            copyPtr->random = mp[ogPtr->random];
            copyPtr=copyPtr->next;
            ogPtr=ogPtr->next; 
        }

        //step 4: return the head of copied ll
        return copyHead;

    }
*/


/*
Appraoch 2: without using any additional data structure
step 1: Create deep nodes of all nodes. Instead of storing these nodes in a hashmap, we will point it to the next of the original nodes.
step 2: Take a pointer, say itr, point it to the head of the list. This will help us to point random pointers as per the original list. This can be achieved by itr->next->random = itr->random->next
step 3: separate the original linked list with the deep nodes list.

TC: O(N), SC: O(1)
*/
/*
Node* copyRandomList(Node* head) {
        //step 1: insert copy nodes in between nodes of original list
        Node*iter=head;
        Node*forward=nullptr;
        while(iter){
            forward=iter->next;
            Node*copyNode = new Node(iter->val);
            copyNode->next = forward;
            iter->next = copyNode;
            iter=forward;
        }

        //step 2: copy random pointers of original ll to copied ll
        iter=head;
        while(iter){
            if(iter->random){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        //step 3: revert changes back to both copied and original ll
        iter=head;
        Node*dummy = new Node(-1);
        Node*ptr = dummy;
        while(iter){
            ptr->next = iter->next;
            ptr = ptr->next;
            iter->next = iter->next->next;
            iter = iter->next;
        }

        //step 4: return the head of copied ll
        return dummy->next;

    }
*/
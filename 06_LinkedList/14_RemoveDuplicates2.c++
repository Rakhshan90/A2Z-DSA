/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.
*/

/*
Approach : By using hashing
1. start traversing the given list and keep track of each node in the map.
2. if curr's node data already exists in the map, that means duplicate node founded, so remove it form the given list but before detetion keep track of curr's next next node.
3. otherwise, keep moving and tracking the nodes in the map.


TC:O(n), SC:O(1)
*/

/*
Node * removeDuplicates( Node *head) 
    {
        unordered_map<int, bool>mp;
        Node*pre=nullptr;
        Node*curr=head;
        while(curr){
            if(mp[curr->data]!=true){
                mp[curr->data]=true;
                pre=curr;
                curr=curr->next;
            }
            else{
                //remove
                pre->next = curr->next;
                delete curr;
                curr=pre->next;
            }
           
        }
        return head;
    }
*/
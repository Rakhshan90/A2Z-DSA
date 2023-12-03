/*Problem Statement: 
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

/*
Approach: By using DLL and Hashmap

Intuition:
While inserting the {key,val} pair into the DDL make sure that we are inserting it from the back tail to head.
The cache will tell us when the {key, value} pair is used/inserted.

TC: O(n)
*/

/*
class LRUCache {
public:
    class node{
        public:
        int key, val;
        node*next;
        node*prev;
        node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    node*head = new node(-1, -1);
    node*tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*>mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void add(node*newNode){
        node*temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void remove(node*delNode){
        node*delPrev = delNode->prev;
        node*delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            node*temp = mp[key];
            int res = temp->val;
            mp.erase(key);
            remove(temp);
            add(temp);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node*existingNode = mp[key];
            mp.erase(key);
            remove(existingNode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            remove(tail->prev);
        }

        add(new node(key, value));
        mp[key] = head->next;
    }
};
*/
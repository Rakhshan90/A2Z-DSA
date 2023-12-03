/*
Problem statement: Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

/*
Approach : Concept of LRU + additional map called freqListMap
We are using same concept of LRU, additionaly we are using map called freqListMap which stores pair of frequecny and corresponding list.

Key data structures:
1. keyNode: Map key to its corresponding Node
2. freqListMap: Map frequency to its corresponding List of nodes
3. minFreq: Tracks the minimum frequency in the cache

get(key):
1. Check if key exists in keyNode.
2. If yes, update its frequency and list, return its value.
3. If no, return -1.

put(key, value):
1. Check if key exists in keyNode.
2. If yes, update its value and frequency.
3. If no:
3.a. If cache full, evict the least frequent node (from minFreq list).
3.b. Create a new node for key, add it to minFreq list and update keyNode.
3.c. Update minFreq if needed.

Key operations:
updateFreqListMap(node): Updates node's frequency, removes it from old list, adds to new list, and updates minFreq if needed. 

TC: O(n)
*/

/*
struct Node{
    int val, key, cnt;
    Node*next;
    Node*prev;
    Node(int key, int val){
        this->val = val;
        this->key = key;
        cnt = 1;
    }
};
struct List{
    int size;
    Node*head;
    Node*tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void add(Node*newNode){
        Node*temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void remove(Node*delNode){
        Node*delPrev = delNode->prev;
        Node*delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};
class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int currCacheSize;
    int maxCacheSize;
    int minFreq;
public:
    LFUCache(int capacity) {
        maxCacheSize = capacity;
        currCacheSize = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node*node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->remove(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        
        List*nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node->cnt += 1;
        nextHigherFreqList->add(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node*existingNode = keyNode[key];
            int res = existingNode->val;
            updateFreqListMap(existingNode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCacheSize == 0) return;

        if(keyNode.find(key) != keyNode.end()){
            Node*existingNode = keyNode[key];
            existingNode->val = value;
            updateFreqListMap(existingNode);
        }
        else{
            if(currCacheSize == maxCacheSize){
                List*list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->remove(list->tail->prev);
                currCacheSize--;
            }
            currCacheSize ++;
            // new value has to be added who is not there previously 
            minFreq = 1;
            List*freqList = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                freqList = freqListMap[minFreq];
            }
            Node*newNode = new Node(key, value);
            freqList->add(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = freqList;
        }
    }
};
*/
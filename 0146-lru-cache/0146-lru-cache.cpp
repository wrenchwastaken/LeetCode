//doubly linked list for 0[1] operations
class Node{
    public: 
    //key and val
    int key;
    int val;
    //two pointers 
    Node* next;
    Node* prev;
    //constuctor for node
    Node(){
        key = -1;
        val = -1;
        next = nullptr;
        prev = nullptr;
    }
    //constructor for node mapping
    Node(int k, int value){
        key = k;
        val = value;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
    //taking a map, capacity, head and tail
    map<int, Node*> mpp;
    int cap;
    Node* head;
    Node* tail;
private:
    //delete from linked list
    void DeleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
    //insert after head
    void insertAfterHead(Node* node){
        Node* nextNode = head->next;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        node->next = nextNode;
    }
public:
    LRUCache(int capacity) {
        //re initiate the cache
        cap = capacity;
        mpp.clear();
        //make linked list nodes and attach them
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //check map for availability
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        //if found store in node
        Node* node = mpp[key];
        int val = node->val;
        DeleteNode(node);
        insertAfterHead(node);
        return val;
    }
    
    void put(int key, int value) {
        //if found in map then update
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            DeleteNode(node);
            insertAfterHead(node);
            return;
        }
        if(mpp.size() == cap){
            Node* node = tail->prev;
            mpp.erase(node->key);
            DeleteNode(node);
        }
        Node* newNode = new Node(key,value);
        mpp[key] = newNode;
        insertAfterHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
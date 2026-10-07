class LRUCache {
private:
    // defining doubly linked list
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k , int v) : key(k), val(v), prev(nullptr), next(nullptr){}
    };

    int capacity;
    unordered_map<int,Node*> cache; // maps key ---> node pointer for O(1) lookup
    Node* head;
    Node* tail;

    // helper function inserts a node directly after the dummy head (mark as most recent)
    void addNode(Node* node){
        node-> prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // helper : severs a node's connnections to extract it from the list
    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        // dummy node to avoid null pointer edge case dureing insertions/ removal
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next  = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];

            // refresh the node's age by moving it to front
            removeNode(node);
            addNode(node);

            return node->val;
        }

        return -1; // key not found
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            // if key already exists, update its value and move it to the front
            Node* node = cache[key];
            node->val = value;
            removeNode(node);
            addNode(node);
        } else {
            // if cache if full, evict the least recently used item
            if(cache.size() == capacity){
                Node* lru = tail->prev;

                cache.erase(lru->key);
                removeNode(lru);
                delete lru;
            }

            // create a new node add it to the map and insert it to the front
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
        }
    }
};

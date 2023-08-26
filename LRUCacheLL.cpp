  //HAD NO CLUE HOW TO IMPLEMENT
//REVIE 5 TIMES
class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};

//abv is dll and below is sth else
class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache; // Key -> (Value, Iterator in lruOrder)
    list<int> lruOrder; // Keeps track of the order in which keys were used
    void updateLRUOrder(int key) {
        lruOrder.erase(cache[key].second);
        lruOrder.push_back(key);
        cache[key].second = prev(lruOrder.end());
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            updateLRUOrder(key);
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            updateLRUOrder(key);
            cache[key].first = value;
        } else {
            if (cache.size() >= capacity) {
                int lruKey = lruOrder.front(); // Get the least recently used key
                lruOrder.pop_front();
                cache.erase(lruKey);
            }
            lruOrder.push_back(key);
            cache[key] = make_pair(value, prev(lruOrder.end()));
        }
    }
};

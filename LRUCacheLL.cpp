  //HAD NO CLUE HOW TO IMPLEMENT
//REVIE 5 TIMES

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

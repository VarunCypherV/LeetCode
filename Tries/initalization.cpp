class TrieNode {
public:
    TrieNode* children[26];
    bool eow; 
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        eow = false;
    }
};

class Trie {
public:
    TrieNode* root ; //for global
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode(); 
            }
            node = node->children[idx]; 
        }
        node->eow = true;
    }
    
    bool search(string word) {
        TrieNode* node = root; 
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return node->eow;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }

    
};

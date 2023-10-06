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

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->eow = true;
    }

    bool searchInNode(string word, TrieNode* node, int index) {
        for (int i = index; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] != nullptr &&
                        searchInNode(word, node->children[j], i + 1)) {
                        return true;
                    }
                }
                return false;  // . but no word after
            } else {
                //regular proceedure
                int idx = c - 'a';
                if (node->children[idx] == nullptr) {
                    return false; 
                }
                node = node->children[idx];
            }
        }
        return node->eow;
    }

    bool search(string word) {
        return searchInNode(word, root, 0);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


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

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->eow = true;
    }

    bool searchInNode(string word, TrieNode* node, int index) {
        if (index == word.size()) {
            return node->eow;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                //if any one children is not null and on further search matches word
                if (node->children[i] != nullptr &&
                    searchInNode(word, node->children[i], index + 1)) {
                    return true;
                }
            }
        } else {
            //regular search
            int idx = word[index] - 'a';
            if (node->children[idx] != nullptr) {
                return searchInNode(word, node->children[idx], index + 1);
            }
        }

        return false;
    }

    bool search(string word) {
        return searchInNode(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

//COME BACK AFTER BACKTRACKING


class Trie {
public:
    Trie* children[26] = {};
    bool eow = false;
    string wordVal = "";

    void addWord(string word) {
        Trie* node = this;  // Start from the current Trie object (root).
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();  // Create a new Trie node.
            }
            node = node->children[idx];  // Move to the child node.
        }
        node->eow = true;
        node->wordVal = word; //if eow true , what word
    }
};


class Solution {
public:
    int vis[13][13] = {};

    void dfs(vector<vector<char>>& board, vector<string>& ans, int i, int j, Trie* root) {
        if (root->eow) {
            ans.push_back(root->wordVal);
            root->eow = false;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j]) return;
        vis[i][j] = 1;

        char currentChar = board[i][j];
        Trie* childNode = root->children[currentChar - 'a'];
        if (childNode) {
            dfs(board, ans, i + 1, j, childNode);
            dfs(board, ans, i - 1, j, childNode);
            dfs(board, ans, i, j + 1, childNode);
            dfs(board, ans, i, j - 1, childNode);
        }
        vis[i][j] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie root;
        vector<string> ans;
        // Add the words to the Trie
        for (const string& word : words) {
            root.addWord(word);
        }
        //DFS each cell
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, ans, i, j, &root);
            }
        }
        return ans;
    }
};

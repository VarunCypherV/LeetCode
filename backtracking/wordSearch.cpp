class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, 0, i, j)) { //taking every cell and trying to make a path and find the word
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index == word.size()) {
            return true;
        }
        //boundary check and checking if letter doesnt match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        char original = board[i][j];
        board[i][j] = '*'; //append

        bool found = backtrack(board, word, index + 1, i + 1, j) ||
                     backtrack(board, word, index + 1, i - 1, j) ||
                     backtrack(board, word, index + 1, i, j + 1) ||
                     backtrack(board, word, index + 1, i, j - 1);

        board[i][j] = original; // pop

        return found;
    }
};

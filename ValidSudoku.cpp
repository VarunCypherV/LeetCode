class Solution {
public:
    unordered_map<char, int> hmap;
    void setHmapTrue() {
        for (char ch = '1'; ch <= '9'; ch++) {
            hmap[ch] = 1;
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            setHmapTrue();
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current == '.') {
                    continue;
                } else if (hmap[current] == 1) {
                    hmap[current]--;
                } else {
                    return false;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            setHmapTrue();
            for (int i = 0; i < 9; i++) {
                char current = board[i][j];
                if (current == '.') {
                    continue;
                } else if (hmap[current] == 1) {
                    hmap[current]--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int flag) { //flag=1 row, flag=0 col
        unordered_map<char, int> hmap;
        for (char ch = '1'; ch <= '9'; ch++) {
            hmap[ch] = 0;
        }
        for (int j = 0; j < 9; j++) {
            char current = (flag == 1) ? board[row][j] : board[j][row]; 
            if (current == '.') {
                continue;
            } else if (hmap[current] == 0) {
                hmap[current]++;
            } else {
                return false;
            }
        }
        return true;
    }
    bool isValidSubgrid(vector<vector<char>>& board, int startRow, int startCol) {
        unordered_map<char, int> hmap;
        for (char ch = '1'; ch <= '9'; ch++) {
            hmap[ch] = 0;
        }
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                char current = board[i][j];
                if (current == '.') {
                    continue;
                } else if (hmap[current] == 0) {
                    hmap[current]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValid(board, i, 1) || !isValid(board, i, 0)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidSubgrid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};

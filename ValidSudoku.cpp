// best optimization : array not hashmap 
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int flag) { //flag=1 row, flag=0 col
        int occurrences[10] = {0};
        for (int j = 0; j < 9; j++) {
            char current = (flag == 1) ? board[row][j] : board[j][row];
            if (current == '.') {
                continue;
            }
            int digit = current - '0';
            if (occurrences[digit] == 0) {
                occurrences[digit]++;
            } else {
                return false;
            }
        }
        return true;
    }
    bool isValidSubgrid(vector<vector<char>>& board, int startRow, int startCol) {
        int occurrences[10] = {0};
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                char current = board[i][j];
                if (current == '.') {
                    continue;
                }
                int digit = current - '0'; // converts into integer
                if (occurrences[digit] == 0) {
                    occurrences[digit]++;
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
        for (int box = 0; box < 9; box++) {
            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;
            if (!isValidSubgrid(board, startRow, startCol)) {
                return false;
            }
        }

        return true;
    }
};


//not the max optimization hashmap
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

        for (int box = 0; box < 9; box++) {
            int startRow = (box / 3) * 3; //round down : 0,3,6
            int startCol = (box % 3) * 3; //round 0,3,6
            if (!isValidSubgrid(board, startRow, startCol)) {
                return false;
            }
        }

        return true;
    }
};

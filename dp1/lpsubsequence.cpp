//HAS BOTH COUNT AND WORD

class Solution {
public:
    string longestPalindrome(string s) {
        string sr = s;
        reverse(sr.begin(), sr.end());
        int n = s.size();
        vector<vector<pair<int, string>>> memo(n + 1, vector<pair<int, string>>(n + 1, {-1, ""}));
        return longestCommonSubsequenceHelper(s, sr, n, n, memo).second;
    }

    pair<int, string> longestCommonSubsequenceHelper(string &text1, string &text2, int i, int j, vector<vector<pair<int, string>>> &memo) {
        if (memo[i][j].first != -1) {
            return memo[i][j];
        }

        if (i == 0 || j == 0) {
            memo[i][j] = {0, ""};
        } else if (text1[i - 1] == text2[j - 1]) {
            auto result = longestCommonSubsequenceHelper(text1, text2, i - 1, j - 1, memo);
            memo[i][j] = {1 + result.first, result.second + text1[i - 1]};
        } else {
            auto result1 = longestCommonSubsequenceHelper(text1, text2, i - 1, j, memo);
            auto result2 = longestCommonSubsequenceHelper(text1, text2, i, j - 1, memo);

            if (result1.first > result2.first) {
                memo[i][j] = result1;
            } else {
                memo[i][j] = result2;
            }
        }

        return memo[i][j];
    }
};
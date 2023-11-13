class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // Check if the substring [j, i) can be segmented and if the substring [j, i) is in the wordDict
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

class Solution {
public:
    int wordBreakCount(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1; // Empty string is always a valid segmentation

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // Check if the substring [j, i) can be segmented and if the substring [j, i) is in the wordDict
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] += dp[j];
                }
            }
        }

        return dp[s.size()];
    }
};
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        // Initialize a vector to store the number of ways to decode up to each position
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1; // Empty string can be decoded in one way
        
        for (int i = 1; i <= s.size(); i++) {
            // Single digit
            if (s[i - 1] != '0') {   //on its own basically dp[i] += no of ways prev one + 1 
                dp[i] += dp[i - 1];
            }
            // Two digits
            if (i >= 2) {
                int twoDigits = stoi(s.substr(i - 2, 2));
                if (twoDigits >= 10 && twoDigits <= 26) {
                }
            }
        }

        return dp[s.size()];
    }
};
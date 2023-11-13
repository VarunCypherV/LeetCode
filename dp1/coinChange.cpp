class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize a vector to store the minimum number of coins needed for each amount.
        vector<int> dp(amount + 1, INT_MAX);
        // Base case: 0 coins needed to make amount 0.
        dp[0] = 0;
        // Iterate through each coin and update the dp array.
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                // Update dp[i] only if it improves the current number of coins needed.
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        // Check if the amount can be made up by any combination of coins.
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};




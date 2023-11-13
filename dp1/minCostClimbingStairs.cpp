// #include <vector>
// #include <algorithm>

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> memo(n, -1);
//         return min(minCost(cost, n - 1, memo), minCost(cost, n - 2, memo));
//     }

// private:
//     int minCost(vector<int>& cost, int step, vector<int>& memo) {
//         // Base case: If step is less than 0, the cost is 0
//         if (step < 0) {
//             return 0;
//         }
//         if (memo[step] != -1) {
//             return memo[step];
//         }
//         memo[step] = cost[step] + min(minCost(cost, step - 1, memo), minCost(cost, step - 2, memo));
//         return memo[step];
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0 || n == 1) { 
            return 0;  // Should return 0 for an empty or single-step staircase
        }
        vector<int> dp(n + 1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // The minimum cost to reach the top can be either from the last step or the second-to-last step
        return min(dp[n - 1], dp[n - 2]);
    }
};

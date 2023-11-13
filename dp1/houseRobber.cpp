#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};







class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return max(maxCost(nums, n - 1, memo), maxCost(nums, n - 2, memo));
    }

    int maxCost(vector<int>& nums, int step, vector<int>& memo) {
        if (step < 0) {
            return 0;
        }
        if (memo[step] != -1) {
            return memo[step];
        }
        memo[step] = nums[step] + max(maxCost(nums, step - 2, memo), maxCost(nums, step - 3, memo));
        return memo[step];
    }
};






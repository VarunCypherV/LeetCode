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
         else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        // Rob first house and exclude last one
        int result1 = robHelper(nums, 0, n - 2);
        // Rob last house and exclude first one
        int result2 = robHelper(nums, 1, n - 1);
        return max(result1, result2);
    }

private:
    int robHelper(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }

        return dp[n - 1];
    }
};


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
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> memo(n, -1);
        int result1 = robHelper(nums, 0, n - 2, memo);
        fill(memo.begin(), memo.end(), -1);
        int result2 = robHelper(nums, 1, n - 1, memo);
        return max(result1, result2);
    }

private:
    int robHelper(vector<int>& nums, int start, int end, vector<int>& memo) {
        if (start > end) {
            return 0;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        memo[start] = max(robHelper(nums, start + 2, end, memo) + nums[start],
                         robHelper(nums, start + 1, end, memo));

        return memo[start];
    }
};

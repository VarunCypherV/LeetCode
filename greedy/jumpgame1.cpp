class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; i++) {
            if (i > farthest) {
                // If the current index is beyond the farthest reachable position, return false
                return false;
            }

            farthest = max(farthest, i + nums[i]); //curr pos + distance possible
            if (farthest >= n - 1) { //>= cuz if 2 then 1 or 2 jump
                // If the farthest position can reach the end, return true
                return true;
            }
        }

        return farthest >= n - 1;
    }
};

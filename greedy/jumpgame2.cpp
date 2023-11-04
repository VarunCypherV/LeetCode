class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int minj = 0;
        int lastJump = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == lastJump) { // If you reach the current jump limit, make a jump
                minj++;
                lastJump = farthest;
            }
        }
        return minj;
    }
};

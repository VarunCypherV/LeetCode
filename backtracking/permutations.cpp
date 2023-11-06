class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false); // To keep track of used elements
        perm(nums, current, result, used);
        return result;
    }

    void perm(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                current.push_back(nums[i]);
                used[i] = true;
                perm(nums, current, result, used);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};

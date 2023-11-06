class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;       
        sort(nums.begin(), nums.end());   //so that if dupe nos they stay next to each other
        backtrack(nums, current, result, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int start) {
        result.push_back(current); 
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) { //if same number then dupe will come so skip
                continue;
            }
            // Include
            current.push_back(nums[i]);
            backtrack(nums, current, result, i + 1); 
            // Exclude
            current.pop_back();
        }
    }
};

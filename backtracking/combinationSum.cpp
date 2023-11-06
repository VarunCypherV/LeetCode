class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        check(candidates, result, current, target, 0);
        return result;
    }

    void check(vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int target, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]); // Add the current candidate to the combination
                check(candidates, result, current, target - candidates[i], i); // Recursively search with the reduced target
                current.pop_back(); // Backtrack by removing the last element to try other combinations
            }
        }
    }
};

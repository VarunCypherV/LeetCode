class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        check(candidates, result, current, target, 0);
        return result;
    }

    void check(vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int target, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if (candidates[i] <= target) {
                current.push_back(candidates[i]); // Add the current candidate to the combination
                check(candidates, result, current, target - candidates[i], i+1); // Recursively search with the reduced target
                current.pop_back(); // Backtrack by removing the last element to try other combinations
            }
        }
    }
};


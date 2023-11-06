class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(nums, result, current, 0);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int start) {
        
        result.push_back(current); //Current SUbset say after num[i] is included we reach here that is a possiblity so add 

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]); //include num[i]

            // Recursively generate subsets with the num[i] included
            backtrack(nums, result, current, i + 1);

            //exclude num[i]
            current.pop_back();
        }
    }
};

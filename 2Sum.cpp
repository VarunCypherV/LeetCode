class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        for(int i=0;i<nums.size();i++){
            int res=target-nums[i];
            result.push_back(i);
            for(int j=i+1;j<nums.size();j++){
                if (nums[j]==res){
                    result.push_back(j);
                    return result;
                }
            }
            result.pop_back();
        }
        return result;
    }
};

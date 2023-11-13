class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod1 = nums[0],prod2 = nums[0],result = nums[0];
        for(int i=1;i<nums.size();i++) {
            int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
            prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]}); //tracks min
            prod1 = temp; //tracks max
            result = max(result,prod1);
        }
        return result;
    }
};

//see neetcode video for underdtanding :
//     [2      3      -2           4               0     -5]
// min: 2      2      -12         -48 prod2*4     -48    -48  prod2
// max: 2      6       6          24               24     240 prod1
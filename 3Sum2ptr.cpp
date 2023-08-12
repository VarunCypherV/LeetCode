class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {  
            if (i > 0 && nums[i] == nums[i - 1]) continue;  //dupe skip since same value element shud be starting element again eg is -1 -1 0 , first -1 is starting then iteration down left-right then coems back to for loop for second element , this second -1 will yeold same result so yea dont.
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    //if left or reight ptr advances to element with same value , it wud yeild result that has already been got
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        
        return result;
    }
};

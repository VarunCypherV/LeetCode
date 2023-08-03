class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int max=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                count++;
                continue;
            }
            if(count>max){
                    max=count+1;
            }           
        }   
        return max;
    }
};

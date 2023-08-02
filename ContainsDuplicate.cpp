class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int length=sizeof(nums)/sizeof(nums[0]);
        int count=0;
        for(int i=0;i<length;i++){
            int target=nums[i]; 
            for(int j=i+1;j<length-2;j++){
                if(target==nums[j]){
                    return true;
                } 
            }
        }
    return false;
    }
};

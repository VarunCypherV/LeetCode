//Bs with recursion


//Bs without Recursion
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int m = left + (right-left)/2;
        while(left<right){
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                right=m-1;
            }
            else{
                left=m+1;
            }
        }
        return left;
    }
};

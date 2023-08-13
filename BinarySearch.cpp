class Solution {
public:

    int BinarySearch(vector<int>& nums, int target , int l , int r){
    
        int m = l + (r-l)/2;
        if(l>r){
            return -1;
        }
        if(nums[m]==target){
            return m;
        }
        else if(nums[m]>target){
            return BinarySearch(nums,target,l,m-1);
        }
        else{
            return BinarySearch(nums,target,m+1,r);
        }
        return -1; //if not found
        
    }

    int search(vector<int>& nums, int target) {
           int l=0;
           int r=nums.size()-1;
           return BinarySearch(nums,target,l,r);
    }
};

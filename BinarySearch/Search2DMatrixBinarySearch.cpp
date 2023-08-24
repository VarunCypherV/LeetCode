class Solution {
public:
    int BinarySearch(vector<int> nums,int target , int  l ,int r){
        int m=l+(r-l)/2;
        if(l>r){return -1;}
        if(nums[m]==target){return m;}
        else if(nums[m]>target){
            return BinarySearch(nums,target,l,m-1);
        }
        else{
            return BinarySearch(nums,target,m+1,r);
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //sorted in non dec order ie ascending 
        int index;
        
        for(int i=0;i<=matrix.size()-1;i++){
            index=BinarySearch(matrix[i],target,0,matrix[0].size()-1);
            if(index!=-1){break;}
        }
        if(index!=-1){
            return true;
        }
        else{
            return false;
        }
    }
};

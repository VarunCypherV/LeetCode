class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left =0 , right =0 , sum=0 , max=INT_MIN;
        vector<int> result;
        vector<int> maxresult;
        while(left+k-1 < nums.size()){
            for(int i=left;i<left+k;i++){
                sum+=nums[i];
                result.push_back(nums[i]);
            }
            if(sum>max){
                max=sum;
                maxresult=result;
            }
            result.clear();
            left++;
        }

        return maxresult;

    }
};

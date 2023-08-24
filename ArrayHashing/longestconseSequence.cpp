class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>::iterator itr;
        itr = unique(nums.begin(), nums.end());
        nums.resize(std::distance(nums.begin(), itr));
        int count=0;
        int max=-1000000000;
        int flag=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                count++;            
                if(i==nums.size()-1){flag=2;}
                continue;
            }
            else{
                if(count>=max){
                    flag=1;
                    max=count+1;
                } 
                count=0;
            }
        }
        if(!nums.size()>0){
            return 0;
        }
        if((flag==0 || flag==2)&& count>=max){
               max=count+1;
        }   
        return max;
    }
};

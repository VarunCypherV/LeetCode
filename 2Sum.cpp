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



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        int equal_k=0;
        int equal_kf=0;
        for(int i=0;i<nums.size();i++){
            auto key=target-nums[i];
            auto key_ind=find(nums.begin(),nums.end(),key);
            auto keyf=key_ind - nums.begin();
            if(i!=keyf){
                if(key_ind!=nums.end()){
                result.push_back(i);
                result.push_back(keyf);
                return result;
                }
            }
            else{
                equal_k=i;
                equal_kf=keyf;
            }
            }
            
     if(equal_k!=0){
            result.push_back(equal_k);
            result.push_back(equal_kf);
     }        
     return result;
        }
};



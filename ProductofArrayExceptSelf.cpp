class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int product=1;
        for(int k=0;k<nums.size();k++){
            for(int i=0;i<nums.size();i++){
                if(i==k){
                    continue;
                }
                product=product*nums[i];
            }
            answer.push_back(product);
            product=1;
        }
        return answer;
    }
};

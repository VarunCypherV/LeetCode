//basically left prod right prod but on same array : kinda dp

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};

//brute force

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

//left product right prodcut of a element for O(n) , bad optimization
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        unordered_map<int,int> lprod;
        unordered_map<int,int> rprod;
        int product=1;
        for(int i=0;i<nums.size();i++){
                lprod[i]=1;
                rprod[i]=1;
        }
        for(int i =1;i<nums.size();i++){
            product=product*nums[i-1];
            lprod[i]=product; 
        }
        product=1;
        for(int i =nums.size()-1;i>=0;i--){
            product=product*nums[i];
            rprod[i-1]=product; 
        }
        for(auto& x:rprod){
            std::cout<<x.first<<"-"<<x.second<<endl;
        }
        for(int i =0;i<nums.size();i++) {
            answer.push_back(lprod[i]*rprod[i]);
        }
        return answer;
    }
};


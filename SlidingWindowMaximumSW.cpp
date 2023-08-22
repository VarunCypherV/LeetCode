//CONCEPTs CRTC BUT TLE

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left =0 , right =0 , sum=0 , max=INT_MIN;
        vector<int> result;
        vector<int> maxresult;
        while(left+k-1 < nums.size()){
            for(int i=left;i<left+k;i++){
                if(nums[i]>max){
                    max=nums[i];
                }
            }
            maxresult.push_back(max);
            left++;
            max=INT_MIN;
        }
        return maxresult;

    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 1, right = 0, sum = 0, max = INT_MIN;
        vector<int> maxresult;
        for (int i = 0; i < k; i++) {
            if (max < nums[i]) {
                max = nums[i];
            }
        }
        maxresult.push_back(max);
        while (left + k - 1 < nums.size()) {
            if (nums[left + k - 1] > max) {
                max = nums[left + k - 1];
            } else if (nums[left - 1] == max) {
                max = INT_MIN;
                for (int i = left; i <= left + k - 1; i++) {
                    if (max < nums[i]) {
                        max = nums[i];
                    }
                }
            }
            maxresult.push_back(max);
            left++;
        }

        return maxresult;
    }
};

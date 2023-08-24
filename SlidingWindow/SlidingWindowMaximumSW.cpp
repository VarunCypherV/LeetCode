//NEED TO REVIEW NEW DATA STRUCTURES
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Store indices of elements
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices of elements that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove indices of elements that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i); // Add the current index to the deque
            
            // The front of the deque contains the maximum element index for the current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> maxHeap; // Pair of (value, index)
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements from the maxHeap that are out of the current window
            while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            
            maxHeap.push({nums[i], i}); // Add the current element to the maxHeap
            
            // The top of the maxHeap contains the maximum element for the current window
            if (i >= k - 1) {
                result.push_back(maxHeap.top().first);
            }
        }
        
        return result;
    }
};





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

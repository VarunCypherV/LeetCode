class Solution {
public:
    int BinarySearch(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return nums[l];
        }
        int m = l + (r - l) / 2;
        if (nums[m] > nums[r]) {
            return BinarySearch(nums, m + 1, r);
        } else {
            return BinarySearch(nums, l, m);
        }
    }

    int findMin(vector<int>& nums) {
        return BinarySearch(nums, 0, nums.size() - 1);
    }
};


//NOTE BELOW IS A BS SOLN WITHOUT RECURSION
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

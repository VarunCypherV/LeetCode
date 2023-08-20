class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto x : nums2) {
            nums1.push_back(x);
        sort(nums1.begin(), nums1.end());
        int size = nums1.size();
        if (size % 2 == 0) {
            int middle1 = nums1[size / 2 - 1];
            int middle2 = nums1[size / 2];
            return static_cast<double>(middle1 + middle2) / 2.0;
        } else {
            return static_cast<double>(nums1[size / 2]);
        }
    }
};

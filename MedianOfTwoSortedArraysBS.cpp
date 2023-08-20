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

//better BS soln
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int n = n1 + n2;
        int left = (n + 1) / 2;
        int low = 0, high = n1;
        while (low <= high) {
            int mid1 = (low + high) /2; // median of shorter
            int mid2 = left - mid1;
            // finding two mids
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            //l1 and r1 r elements immediately to the left and and right of calculated mids
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int missing = nums.size(); // Initialize with the last index ie last number

        //expected value at index i is nums[i] but that will equal to i since [0,n]
        // The idea is that if the array were complete (with no missing number), each index i should have the value i. The XOR operation cancels out the common values, leaving only the missing number.
        for (int i = 0; i < nums.size(); ++i) {
            missing ^= i ^ nums[i]; //if i and nums[i] match then it cancels out so no change
        }

        return missing;
    }
};

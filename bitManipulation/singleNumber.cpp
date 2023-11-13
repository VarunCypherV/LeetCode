class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        //concept A^A=0 so only the left over will be there
        return result;
    }
};

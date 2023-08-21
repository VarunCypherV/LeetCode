class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int left = 0;
        int maxCount = 0; 
        unordered_map<char, int> hmap;
        for (int right = 0; right < s.size(); ++right) {
            hmap[s[right]]++;
            maxCount = max(maxCount, hmap[s[right]]);
            int changeCount = (right - left + 1) - maxCount;
            if (changeCount > k) {
                hmap[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

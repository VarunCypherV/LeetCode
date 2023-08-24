class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> charMap;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (charMap.find(s[right]) != charMap.end()) {
                left = max(left, charMap[s[right]] + 1); // push it directly to where it was alst seen
            }
            charMap[s[right]] = right; //index of where it was found last
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_set<char> charSet;
        for (int right = 0; right < s.size(); ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
    return maxLen;
    }
};
